#ifndef CMGRAPHICSVIEW_H
#define CMGRAPHICSVIEW_H

class MancalaSolver;

#include <QWidget>

class CMGraphicsView : public QWidget
{
    Q_OBJECT
public:
    explicit CMGraphicsView(QWidget *parent = nullptr);
    virtual ~CMGraphicsView();

    void mousePressEvent(QMouseEvent* ev);
    void mouseMoveEvent(QMouseEvent* ev);
    void mouseReleaseEvent(QMouseEvent* ev);
    void paintEvent(QPaintEvent *ev);

signals:

public slots:

private:
    MancalaSolver* m_ms;
};

#endif // CMGRAPHICSVIEW_H
