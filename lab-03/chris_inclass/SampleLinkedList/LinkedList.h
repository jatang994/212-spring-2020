#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class Node
{
public:
    Node* next;
    double data;
};

class LinkedList
{
private:
    Node* head;
    Node* tail;
    int count;

public:
    LinkedList(); //create an empty list
    ~LinkedList(); //delete linked list

    void append(double value);
    void prepend(double value);
    void insert(int index, double value);
    void removeFirst();
    void removeLast();
    void removeAt(int index);
    void removeFirstOf(double value);
    double get(int index);
    void print();
};

#endif // LINKEDLIST_H
