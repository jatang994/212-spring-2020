#include "LinkedList.h"
#include <iostream>

//construct an empty list
LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    count = 0;
}
LinkedList::~LinkedList()
{

}

void LinkedList::append(double value)
{
    //case 1 (list is empty)
    if (count == 0)
    {
        Node *my_node = new Node();
        my_node->data = value;
        my_node->next = nullptr;
        head = my_node;
        tail = my_node;
        count = 1;
    }
    //case 2 (list is not empty)
    else
    {
        Node *my_node = new Node(); //add to the end of the list
        my_node->data = value;
        my_node->next = nullptr;
        tail->next = my_node;
        tail = my_node;
        count += 1; //increase count by 1
    }
}

void LinkedList::prepend(double value)
{

}

void LinkedList::insert(int index, double value)
{

}

void LinkedList::removeFirst()
{

}

void LinkedList::removeLast()
{
    if (count > 0) //if the list is not empty remove last item otherwise do nothing
    {
        if (count == 1) //list has exactly one item in it
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            count = 0;
        }
        else //list has at least 2 items in it
        {
            Node* current = head;
            Node* previous = head;
            while (current != tail) //go to the second to last item in the list
            {
                previous = current;
                current = current->next;
            }

            //previous will point to the second to last item in the list
            previous->next = nullptr;
            delete tail;
            tail = previous;
        }
    }
}

void LinkedList::removeAt(int index)
{

}

void LinkedList::removeFirstOf(double value)
{

}

double LinkedList::get(int index)
{

}

void LinkedList::print()
{
    if (count == 0)
        std::cout << "{}" << std::endl;
    else
    {
        Node* current = head;
        std::cout << "{";
        while (current != nullptr)
        {
            std::cout << current->data;
            if (current != tail)
                std::cout << ", ";
            current = current->next;

        }
        std::cout << "}" << std::endl;
    }
}
