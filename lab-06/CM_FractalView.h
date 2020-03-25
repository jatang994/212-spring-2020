#ifndef CM_FRACTALVIEW_H
#define CM_FRACTALVIEW_H

#include <QWidget>

class CM_Renderer;
class Fractal;

class CM_FractalView : public QWidget
{
    Q_OBJECT
public:
    explicit CM_FractalView(QWidget *parent = nullptr);
    virtual ~CM_FractalView();

protected:
    void paintEvent(QPaintEvent* ev);

signals:

public slots:
    void setNumberOfSteps(int steps);

private:
    CM_Renderer* m_renderer;
    Fractal* m_fractal;
    int m_steps;
};

#endif // CM_FRACTALVIEW_H
