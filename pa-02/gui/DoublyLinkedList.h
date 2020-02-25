/**
 * @file DoublyLinkedList.h
 * @author Christopher McCooey
 * @date February 17, 2020
 * @brief This is the class you will be implementing. You can change this file by adding your own functions
 * if you want but do not have to. Do not change the names or parameters of the existing functions. Do not
 * change the Node data structure or any of its methods. All of the work in this assignment is going to be
 * code changes to DoublyLinkedList.cpp
 */

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <string>

//Node data structure used by the linked list
struct Node
{
    Node* previous;
    Node* next;
    char data;

    Node();
    Node(char c);
};

class DoublyLinkedList
{
private:
    Node* m_head; //always points to the beginning of the list
    Node* m_tail; //always points to the end of the list
    int m_node_count; //represents the number of nodes in the list

public:
    DoublyLinkedList(); //default constructor
    DoublyLinkedList(const DoublyLinkedList& other); //copy constructor
    DoublyLinkedList(const std::string &data_string); //constructor with a specific string (provided)
    ~DoublyLinkedList(); //destructor

    //add to to the end of the list
    //--- (15 pts)
    void append(char data);

    //add to the beginning of the list
    //--- (15 pts)
    void prepend(char data);

    //add to the middle of the list (index = 0) means insert at the beginning of the list
    //--- (15 pts)
    void insert(int index, char data);

    //remove from the end of the list
    //--- (10 pts)
    void removeLast();

    //remove from the beginning of the list
    //--- (10 pts)
    void removeFirst();

    //remove from a specific position in the list
    //--- (10 pts)
    void removeAt(int index);

    //remove all nodes from the linked list
    //--- (5 pts)
    void clear();

    //get a value at a position in the linked list
    //--- (5 pts)
    char get(int index) const;

    //modify a value at a position in the linked list
    //--- (5 pts)
    void set(int index, char new_value);

    //find the first occurence of "search char" in the linked list and return its index position. Return -1 if the character is not found.
    //--- (5 pts)
    int findFirstOf(char search_char) const;

    //find the last occurence of "search_char" in the linked list and return its index position. Return -1 if the character is not found.
    //--- (5 pts)
    int findLastOf(char search_char) const;

    //functions that you do NOT have to implement and should not change
    DoublyLinkedList& operator=(const DoublyLinkedList& other); //deep copy assignment operator
    char operator[](int index) const; //does the same thing as the get function
    Node* firstNode(); //get the first node
    int getSize() const; //get the number of items in the list
    std::string toString() const; //get the data in the linked list as a printable string
};

#endif // DOUBLYLINKEDLIST_H
