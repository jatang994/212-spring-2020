#include "CMGraphicsView.h"
#include "MancalaSolver.h"
#include <QPainter>
#include <QMouseEvent>
#include <QPaintEvent>
#include <cmath>

#define CIRCLE_SIZE 48
#define MARGIN 48
#define MAX_PIECES 100
#define INITIAL_PIECE_WIDTH 8
#define PIECE_HEIGHT 8
#define PIECE_GROWTH_FACTOR 3

CMGraphicsView::CMGraphicsView(QWidget *parent) : QWidget(parent)
{
    m_ms = new MancalaSolver();
}
CMGraphicsView::~CMGraphicsView()
{
    delete m_ms;
}

//mouse events
void CMGraphicsView::mousePressEvent(QMouseEvent* ev)
{
    if (ev->button() == Qt::LeftButton)
    {
        m_ms->append(static_cast<int>(m_ms->getSize()), ev->y() / 100);
        update();
    }
}
void CMGraphicsView::mouseMoveEvent(QMouseEvent* ev)
{
    QWidget::mouseMoveEvent(ev);
}
void CMGraphicsView::mouseReleaseEvent(QMouseEvent* ev)
{
    QWidget::mouseReleaseEvent(ev);
}

//main draw function
void CMGraphicsView::paintEvent(QPaintEvent *ev)
{
    QWidget::paintEvent(ev);
    QPainter painter(this);
    QPen pen;
    QBrush brush;
    unsigned int num_elem;

    //draw the background
    pen.setStyle(Qt::NoPen);
    brush.setColor(QColor(0, 0, 0));
    brush.setStyle(Qt::SolidPattern);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(rect());

    //draw the manacala wheel
    num_elem = m_ms->getSize();
    if (num_elem == 0u)
    {
        pen.setStyle(Qt::SolidLine);
        pen.setColor(QColor(255, 255, 255));
        painter.setPen(pen);
        painter.drawText(rect().center(), QString("Mancala Solver is empty"));
    }
    else
    {
        int screen_min_bounds, diameter, index, num_pieces, x, y, i, piece_width, cx, cy;
        double angle_incr, angle_iter;
        QRect c_rect;

        //calculate the diameter of the circle we want
        screen_min_bounds = height() / 2;
        if (width() / 2 < screen_min_bounds)
            screen_min_bounds = width() / 2;
        diameter = screen_min_bounds - (CIRCLE_SIZE / 2) - MARGIN;

        //calculate the angle in radians in between each circle element
        angle_incr = M_PI * 2.0 / static_cast<double>(num_elem);
        angle_iter = 0.0;

        //determine the starting point of the mancara pinwheel
        cx = width() / 2;
        cy = height() / 2;

        m_ms->cmBegin();
        while (!m_ms->cmAtEnd())
        {
            index = num_pieces = 0;
            m_ms->cmNext(&index, &num_pieces); //get the information about this node and go to the next one

            //determine the x and y position we are going to draw the circle
            x = cx + static_cast<int>(cos(angle_iter) * diameter);
            y = cy + static_cast<int>(sin(angle_iter) * diameter);

            //construct a rectangle to use as a bounding box for a circle around the (x, y) position calculated
            c_rect = QRect(x - CIRCLE_SIZE / 2, y - CIRCLE_SIZE / 2, CIRCLE_SIZE, CIRCLE_SIZE);

            //draw the chord
            pen.setStyle(Qt::SolidLine);
            pen.setColor(QColor(50, 50, 0));
            pen.setWidth(2);
            brush.setColor(QColor(255, 255, 0));
            brush.setStyle(Qt::SolidPattern);
            painter.setPen(pen);
            painter.setBrush(brush);
            painter.drawEllipse(c_rect);
            //painter.drawChord(c_rect, 180, 180);

            //draw text on top of that chord to represent the index
            pen.setColor(QColor(0, 0, 0));
            painter.setPen(pen);
            painter.drawText(c_rect.adjusted(c_rect.width() / 2, CIRCLE_SIZE / 2, 0, 0), QString::number(index));

            //draw a stack of boxes to represent the number of items (they get smaller as we move up the stack)
            piece_width = INITIAL_PIECE_WIDTH + ((num_pieces - 1) * PIECE_GROWTH_FACTOR);
            x = c_rect.center().x() - (piece_width / 2);
            y = c_rect.top();
            pen.setStyle(Qt::SolidLine);
            pen.setColor(QColor(0, 0, 0));
            pen.setWidth(1);
            brush.setColor(QColor(75, 255, 75));
            brush.setStyle(Qt::SolidPattern);
            painter.setPen(pen);
            painter.setBrush(brush);
            for (i = 0; i < num_pieces && i < MAX_PIECES; i++)
            {
                painter.drawRect(QRect(x, y, piece_width, PIECE_HEIGHT));
                piece_width -= PIECE_GROWTH_FACTOR;
                x += (PIECE_GROWTH_FACTOR / 2);
                y -= PIECE_HEIGHT;
            }

            //increase the angle
            angle_iter += angle_incr;
        }
    }



    painter.end();
}
