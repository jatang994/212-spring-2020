#ifndef CM_RENDERER_H
#define CM_RENDERER_H

class QPainter;

class CM_Renderer
{
public:
    CM_Renderer();
    ~CM_Renderer();

    void cmSetRenderSettings(int w, int h, QPainter* painter);
    int fx2px(float fx) const;
    int fy2py(float fy) const;

    //The only functions you need to call (values are between 0 and 100
    void drawLine(int x1, int y1, int x2, int y2);
    void drawLineF(float x1, float y1, float x2, float y2);

private:
    QPainter* m_renderer;
    int m_screen_width;
    int m_screen_height;
};

#endif // CM_RENDERER_H
