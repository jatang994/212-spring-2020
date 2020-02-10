#include "ChrisView.h"
#include <QPaintEvent>
#include <QPainter>

ChrisView::ChrisView(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(true);
    m_tx = m_ty = 0;
    m_show_index = false;
    m_panning = false;
}

void ChrisView::mousePressEvent(QMouseEvent* ev)
{
    if (ev->button() == Qt::LeftButton)
    {
        m_panning = true;
        m_mouse_point = ev->pos();
    }
}
void ChrisView::mouseMoveEvent(QMouseEvent *ev)
{
    if (m_panning)
    {
        QPoint delta = ev->pos() - m_mouse_point;
        //m_tx += delta.x();
        m_ty += delta.y();
        m_mouse_point = ev->pos();
        update();
    }
}
void ChrisView::mouseReleaseEvent(QMouseEvent* ev)
{
    if (ev->button() == Qt::LeftButton)
    {
        m_panning = false;
    }
    else if (ev->button() == Qt::RightButton)
    {
        m_ints.append(rand() % 100);
        update();
    }
    else if (ev->button() == Qt::MiddleButton)
    {
        for (int i = 0; i < 20; i++)
            m_ints.append(rand() % 100);
        update();
    }
}

//find function
unsigned int ChrisView::findValue(bool find_first, int value, bool *found)
{
    unsigned int idx = m_ints.getLength();

    if (find_first)
        *found = m_ints.findFirstOf(value, &idx);
    else
        *found = m_ints.findLastOf(value, &idx);
    return idx;
}

//buttons to edit the array
void ChrisView::requestAppend()
{
    m_ints.append(rand() % 100);
    update();
}
void ChrisView::requestPrepend()
{
    m_ints.prepend(rand() % 100);
    update();
}
void ChrisView::requestRemoveLast()
{
    m_ints.removeLast();
    update();
}
void ChrisView::requestRemoveFirst()
{
    m_ints.removeFirst();
    update();
}
void ChrisView::requestClear()
{
    m_ints.clear();
    update();
}
void ChrisView::showIndexValue(int check_state)
{
    m_show_index = (check_state == Qt::Checked);
    update();
}
void ChrisView::scaleFactorChanged(double value)
{
    m_ints.setScalingFactor(value);
}

//main draw function
void ChrisView::paintEvent(QPaintEvent* ev)
{
    QWidget::paintEvent(ev); //base class event
    QPainter painter(this);
    QBrush brush;
    QPen pen;
    QString text;
    int x, y, w, h;

    //draw the solid color background
    brush.setColor(QColor(0, 0, 0));
    brush.setStyle(Qt::SolidPattern);
    pen.setStyle(Qt::NoPen);
    painter.setBrush(brush);
    painter.setPen(pen);
    painter.drawRect(rect());

    //draw the items in the list
    painter.translate(QPoint(m_tx, m_ty));
    brush.setColor(QColor(255, 255, 150));
    brush.setStyle(Qt::SolidPattern);
    pen.setStyle(Qt::SolidLine);
    pen.setColor(QColor(0, 0, 0));
    painter.setBrush(brush);
    painter.setPen(pen);

    x = 0;
    h = 32;
    w = 32;
    y = height() / 2 - h / 2;
    for (unsigned int i = 0; i < m_ints.getLength(); i++)
    {
        if (m_show_index)
        {
            text = QString::number(i);
            text.push_back(QChar('\n'));
            text.append(QString::number(m_ints[i]));
        }
        else
            text = QString::number(m_ints[i]);

        painter.drawRect(QRect(x, y, w, h));
        painter.drawText(QRect(x + 5, y + 3, w, h), text);

        x += w + 4;
        if (x > width() - w - 4)
        {
            x = 0;
            y += h + 4;
        }
    }
    brush.setColor(QColor(150, 150, 150));
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    for (unsigned int i = m_ints.getLength(); i < m_ints.getCapacity(); i++)
    {
        painter.drawRect(QRect(x, y, w, h));
        if (m_show_index)
            painter.drawText(QRect(x + 5, y + 3, w, h), QString::number(i));
        x += w + 4;
        if (x > width() - w - 4)
        {
            x = 0;
            y += h + 4;
        }
    }

    painter.end();
}
