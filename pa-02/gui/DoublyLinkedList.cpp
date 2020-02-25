/**
 * @file DoublyLinkedList.h
 * @date February 17, 2020
 * @brief This is the class you will be implementing. You will be implementing the unimplemented
 * functions in this file. The best way to start is with the append function.
 */
#include "DoublyLinkedList.h"

//constructors for the linked list
DoublyLinkedList::DoublyLinkedList() //default constructor (empty list)
{
    //I have implemented this for you. This will initialize all the variables in the linked list.
    m_head = nullptr;
    m_tail = nullptr;
    m_node_count = 0;
}
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& other) //copy constructor
{
    (*this) = other; //this will just reuse the code from the assignment operator
}
DoublyLinkedList::DoublyLinkedList(const std::string &data_string)
{
    //This constructor generates a linked list using a string where each node is a character in the string
    if (data_string.size() == 0u)
    {
        m_head = m_tail = nullptr;
        m_node_count = 0;
    }
    else
    {
        std::string::size_type string_length, i;
        string_length = data_string.size();

        m_head = new Node(data_string.at(0));
        m_tail = m_head;
        for (i = 1; i < string_length; i++)
        {
            char character = data_string.at(i);
            Node* new_node = new Node(character);
            new_node->previous = m_tail;
            new_node->next = nullptr;
            m_tail->next = new_node;

            //assign this node as the new tail
            m_tail = new_node;
        }

        //make the list circular
        m_head->previous = m_tail;
        m_tail->next = m_head;

        //set the size correctly
        m_node_count = static_cast<int>(string_length);
    }
}
DoublyLinkedList::~DoublyLinkedList() //destructor
{
    //..............
    // TODO
    //..............
}

//add to to the end of the list
void DoublyLinkedList::append(char data)
{
    //..............
    // TODO
    //..............
}

//add to the beginning of the list
void DoublyLinkedList::prepend(char data)
{
    //..............
    // TODO
    //..............
}

//add to the middle of the list (index = 0) means insert at the beginning of the list
void DoublyLinkedList::insert(int index, char data)
{
    //..............
    // TODO
    //..............
}

//remove from the end of the list
void DoublyLinkedList::removeLast()
{
    //..............
    // TODO
    //..............
}

//remove from the beginning of the list
void DoublyLinkedList::removeFirst()
{
    //..............
    // TODO
    //..............
}

//remove from a specific position in the list
void DoublyLinkedList::removeAt(int index)
{
    //..............
    // TODO
    //..............
}

//remove all nodes from the linked list
void DoublyLinkedList::clear()
{
    //..............
    // TODO
    //..............
}

//get a value at a position in the linked list
char DoublyLinkedList::get(int index) const
{
    //..............
    // TODO
    //..............
}

//modify a value at a position in the linked list
void DoublyLinkedList::set(int index, char new_value)
{
    //..............
    // TODO
    //..............
}

//find the first occurence of "search char" in the linked list and return its position. Return -1 if the character is not found.
int DoublyLinkedList::findFirstOf(char search_char) const
{
    //..............
    // TODO
    //..............
}

//find the last occurence of "search_char" in the linked list and return its position. Return -1 if the character is not found.
int DoublyLinkedList::findLastOf(char search_char) const
{
    //..............
    // TODO
    //..............
}

//functions that you do NOT have to implement
DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& other)
{
    clear();
    if (other.m_node_count > 0)
    {
        Node* o_current, *t_current;

        m_head = new Node(other.m_head->data);
        t_current = m_head;

        o_current = other.m_head->next;
        for (int i = 1; i < other.m_node_count; i++)
        {
            t_current->next = new Node(o_current->data);
            t_current->next->previous = t_current;
            o_current = o_current->next;
            t_current = t_current->next;
        }
        m_tail = t_current;

        m_head->previous = m_tail;
        m_tail->next = m_head;
    }
    return (*this);
}
char DoublyLinkedList::operator[](int index) const
{
    return get(index);
}
Node *DoublyLinkedList::firstNode()
{
    return m_head;
}
int DoublyLinkedList::getSize() const
{
    return m_node_count;
}
std::string DoublyLinkedList::toString() const
{
    std::string str;
    if (m_head != nullptr)
    {
        Node* current = m_head;
        str.reserve(static_cast<std::string::size_type>(m_node_count));
        for (int i = 0; i < m_node_count; i++)
        {
            str.push_back(current->data);
            current = current->next; //move to the next node
        }
    }
    return str;
}
//node constructors
Node::Node() :previous(nullptr), next(nullptr), data('0') {}
Node::Node(char c) :previous(nullptr), next(nullptr), data(c) {}
