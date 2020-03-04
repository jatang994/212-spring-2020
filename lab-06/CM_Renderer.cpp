#include "CM_Renderer.h"
#include <QPainter>

#define MAXSIZE 100.0f

CM_Renderer::CM_Renderer()
    :m_renderer(nullptr), m_screen_width(0), m_screen_height(0)
{

}
CM_Renderer::~CM_Renderer(){}

void CM_Renderer::cmSetRenderSettings(int w, int h, QPainter *painter)
{
    m_screen_width = w;
    m_screen_height = h;
    m_renderer = painter;
}
int CM_Renderer::fx2px(float fx) const
{
    return static_cast<int>((fx / MAXSIZE) * static_cast<float>(m_screen_width));
}
int CM_Renderer::fy2py(float fy) const
{
    return static_cast<int>((fy / MAXSIZE) * static_cast<float>(m_screen_height));
}

//drawing functions
void CM_Renderer::drawLine(int x1, int y1, int x2, int y2)
{
    drawLineF(static_cast<float>(x1), static_cast<float>(y1), static_cast<float>(x2), static_cast<float>(y2));
}
void CM_Renderer::drawLineF(float x1, float y1, float x2, float y2)
{
    if (m_renderer == nullptr)
        return;

    m_renderer->drawLine(fx2px(x1), fy2py(y1), fx2px(x2), fy2py(y2));
}
