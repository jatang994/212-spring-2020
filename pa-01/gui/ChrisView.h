/*
 * Author: Christopher McCooey
 * Date Created: January 29, 2020
 * Description: This is the Qt viewport that displays the array. It handles mouse events such as panning. Do not edit the code
 *              that is here other than the #include on line 14.
 */

#ifndef CHRISVIEW_H
#define CHRISVIEW_H

#define USE_TRUE_ARRAY 0

#include <QWidget>
#include <QPoint>

#if USE_TRUE_ARRAY
#include "../DynamicArray_true.h" //used to test the already implemented version of the dynamic array
#else
#include "DynamicArray.h"
#endif

class ChrisView : public QWidget
{
    Q_OBJECT
public:
    explicit ChrisView(QWidget *parent = nullptr);

protected:
    virtual void mousePressEvent(QMouseEvent* ev);
    virtual void mouseMoveEvent(QMouseEvent* ev);
    virtual void mouseReleaseEvent(QMouseEvent* ev);
    virtual void paintEvent(QPaintEvent* ev);

public:
    unsigned int findValue(bool find_first, int value, bool *found);

signals:

public slots:
    void requestAppend();
    void requestPrepend();
    void requestRemoveLast();
    void requestRemoveFirst();
    void requestClear();
    void showIndexValue(int check_state);
    void scaleFactorChanged(double value);

private:
    DynamicArray m_ints;
    QPoint m_mouse_point;
    bool m_panning;
    int m_tx;
    int m_ty;
    bool m_show_index;
};

#endif // CHRISVIEW_H
