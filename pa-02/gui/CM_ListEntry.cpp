/**
 * @file CM_ListEntry.h
 * @author Christopher McCooey
 * @date February 17, 2020
 * @brief This class is the text display widget at the top of the screen. This widget handles the cursor
 * and the keyboard inputs. It is used to update the linked list based on user keyboard input. Do not
 * edit this file.
 */

#include "CM_ListEntry.h"
#ifdef USE_COMPLETED
	#include "DoublyLinkedList_completed.h"
#else
	#include "DoublyLinkedList.h"
#endif
#include <QKeyEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QFontMetrics>

CM_ListEntry::CM_ListEntry(QWidget *parent)
    :QWidget(parent), m_list_ptr(nullptr), m_cursor_index(0), m_font("Verdana", 14, -1, false),
      m_text_offset(4, 0), m_str()
{

}
CM_ListEntry::~CM_ListEntry()
{

}

void CM_ListEntry::mouseReleaseEvent(QMouseEvent *ev)
{
    if (ev->button() == Qt::LeftButton)
    {
        QFontMetrics font_metrics(m_font);
        int x, i, idx = -1;

        //figure out where in the string location clicked
        x = m_text_offset.x();
        for (i = 0; i < m_str.size(); i++)
        {
            if (ev->x() > x)
                idx = i;
            x += font_metrics.horizontalAdvance(m_str.at(i));
        }

        //update the cursor index to the end of the string if the x is beyond the length of the string
        if (idx == -1)
            m_cursor_index = m_str.size();
        else
            m_cursor_index = idx;

        update();
    }
}

bool CM_ListEntry::translateIndex(int amount)
{
    bool changed;
    int idx = m_cursor_index + amount;
    if (idx < 0)
        idx = 0;
    else if (idx > m_list_ptr->getSize())
        idx = m_list_ptr->getSize();
    changed = (idx != m_cursor_index);
    if (changed)
        m_cursor_index = idx;
    return changed;
}
void CM_ListEntry::setIndex(int value)
{
    const int size = m_list_ptr->getSize();
    int idx = value;
    if (idx > size)
        idx = m_list_ptr->getSize();
    if (idx < 0)
        idx = 0;
    if (idx != m_cursor_index)
    {
        m_cursor_index = idx;
        update();
    }
}

void CM_ListEntry::keyPressFunction(QKeyEvent *ev)
{
    QString text = ev->text();
    //std::cout << "DEBUG: text " << text.toStdString() << " key " << ev->key() << std::endl;
    //std::cout.flush();

    bool delete_request = false;
    bool update_only = false;
    switch(ev->key())
    {
    case Qt::Key_Left: update_only = translateIndex(-1); break;
    case Qt::Key_Right: update_only = translateIndex(1); break;
    case Qt::Key_Home: setIndex(0); break;
    case Qt::Key_End: setIndex(m_list_ptr->getSize()); break;
    case Qt::Key_Backspace:
    {
        if (m_cursor_index >= m_list_ptr->getSize())
        {
            m_cursor_index = m_list_ptr->getSize() - 1;
            if (m_cursor_index < 0)
                m_cursor_index = 0;
            m_list_ptr->removeLast();
        }
        else
        {
            m_list_ptr->removeAt(m_cursor_index - 1);
            translateIndex(-1);
        }
        delete_request = true;
        break;
    }
    case Qt::Key_Delete:
    {
        if (m_cursor_index <= 0)
            m_list_ptr->removeFirst();
        else if (m_cursor_index < m_list_ptr->getSize())
            m_list_ptr->removeAt(m_cursor_index);
        delete_request = true;
        break;
    }
    default: delete_request = false; break;
    }

    if (delete_request) //redraw display including parent widget
        updateStr();
    else if (text.size() == 1)
    {
        const char c = text.at(0).toLatin1();
        if (m_cursor_index >= m_list_ptr->getSize())
        {
            m_list_ptr->append(c);
            m_cursor_index++; //move cursor to the next item
        }
        else if (m_cursor_index <= 0)
            m_list_ptr->prepend(c);
        else
            m_list_ptr->insert(m_cursor_index, c);

        updateStr();
    }
    if (update_only && !delete_request) //redraw display without redrawing the parent widget
        update();
}
void CM_ListEntry::setDLL(DoublyLinkedList *dll)
{
    m_list_ptr = dll;
    updateStr();
}

void CM_ListEntry::paintEvent(QPaintEvent *ev)
{
    QWidget::paintEvent(ev);
    QPainter painter(this);
    QFontMetrics font_metrics(m_font);
    QPen pen;
    QBrush brush;
    QRect helper_rect;
    QString helper_text;
    QFont font;
    int x1, y1, x2, y2, node_count = 0;

    if (m_list_ptr != nullptr)
        node_count = m_list_ptr->getSize();

    //draw the background
    pen.setWidth(2);
    pen.setColor(QColor(0, 0, 0));
    pen.setStyle(Qt::SolidLine);
    brush.setColor(QColor(255, 255, 255));
    brush.setStyle(Qt::SolidPattern);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(rect());

    //draw the text
    painter.setFont(m_font);
    painter.drawText(rect().translated(m_text_offset), m_str);

    //draw the cursor
    x1 = m_text_offset.x() + font_metrics.horizontalAdvance(m_str, m_cursor_index) + 1;
    y1 = 2;
    x2 = x1;
    y2 = height() / 2 - 2;
    painter.drawLine(x1, y1, x2, y2);
    painter.drawLine(x1 - 2, y1, x1 + 2, y1);
    painter.drawLine(x1 - 2, y2, x1 + 2, y2);

    //determine helper text
    if (m_cursor_index < node_count)
    {
        if (m_cursor_index == 0)
            helper_text = QString("Type to prepend a character");
        else
            helper_text = QString("Type to insert at index ") + QString::number(m_cursor_index);
    }
    else if (node_count == 0 || m_cursor_index >= node_count)
        helper_text = QString("Type to append a character");

    //draw helper text and box
    font = m_font;
    font.setPointSize(12);
    brush.setColor(QColor(255, 255, 200));
    painter.setBrush(brush);
    helper_rect = QRect(0, y2 + 2, width(), height() - y2 - 2);
    painter.setFont(font);
    painter.drawRect(helper_rect);
    painter.drawText(helper_rect.translated(2, 2), helper_text);//QString::number(m_cursor_index));

    //finish painting sequence
    painter.end();
}

void CM_ListEntry::updateStr()
{
    QWidget* p = parentWidget();
    m_str = QString::fromStdString(m_list_ptr->toString());

    if (p != nullptr)
        p->update(); //the parent widget updates this widget so there is no need to update
    else
        update();
}
