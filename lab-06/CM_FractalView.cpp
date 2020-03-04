#include "CM_FractalView.h"
#include "CM_Renderer.h"
#include "Fractal.h"
#include <QPaintEvent>
#include <QPainter>

CM_FractalView::CM_FractalView(QWidget *parent) : QWidget(parent)
{
    m_renderer = new CM_Renderer();
    m_fractal = new Fractal();
    m_steps = 1;
}
CM_FractalView::~CM_FractalView()
{
    delete m_fractal;
    delete m_renderer;
}

//main draw function
void CM_FractalView::paintEvent(QPaintEvent *ev)
{
    ev->accept();
    QPainter painter(this);
    QPen pen;
    QBrush brush;

    brush.setColor(QColor(0, 0, 0));
    brush.setStyle(Qt::SolidPattern);
    pen.setStyle(Qt::NoPen);

    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(rect());

    //draw fractal and renderer
    if (m_renderer != nullptr && m_fractal != nullptr)
    {
        pen.setStyle(Qt::SolidLine);
        pen.setColor(QColor(255, 255, 255));
        pen.setWidth(1);
        painter.setPen(pen);
        m_renderer->cmSetRenderSettings(width(), height(), &painter);
        m_fractal->draw(m_renderer, m_steps);
    }

    painter.end();
}

void CM_FractalView::setNumberOfSteps(int steps)
{
    if (m_steps != steps)
    {
        m_steps = steps;
        update(); //redraw
    }
}
