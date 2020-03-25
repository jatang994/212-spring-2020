/**
 * @file CM_ListEntry.h
 * @author Christopher McCooey
 * @date February 17, 2020
 * @brief This class is the text display widget at the top of the screen. This widget handles the cursor
 * and the keyboard inputs. It is used to update the linked list based on user keyboard input. Do not
 * edit this file.
 */

#ifndef CM_LISTENTRY_H
#define CM_LISTENTRY_H

#include <QWidget>
#include <QKeyEvent>
#include <QFont>
#include <QPoint>
#include <QString>

class DoublyLinkedList;

class CM_ListEntry :public QWidget
{
public:
    CM_ListEntry(QWidget* parent = nullptr);
    ~CM_ListEntry();

    void keyPressFunction(QKeyEvent* ev);
    void setDLL(DoublyLinkedList* dll);
    bool translateIndex(int amount);
    void setIndex(int value);
    void updateStr();

protected:
    void mouseReleaseEvent(QMouseEvent* ev);
    void paintEvent(QPaintEvent* ev);

private:
    DoublyLinkedList* m_list_ptr;
    int m_cursor_index;
    QFont m_font;
    QPoint m_text_offset;
    QString m_str;
};

#endif // CM_LISTENTRY_H
