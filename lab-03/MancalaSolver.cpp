#include "MancalaSolver.h"
#include "Pit.h"
#include <iostream>

MancalaSolver::MancalaSolver()
{
    cm_current = nullptr;
    head = nullptr;
    tail = nullptr;
    n_elem = 0u;
}

MancalaSolver::~MancalaSolver()
{

}

int MancalaSolver::removeByIndex(unsigned int idx)
{

}

void MancalaSolver::append(int idx, int num_pieces)
{
    
}

int MancalaSolver::solve(int idx)
{

}

unsigned int MancalaSolver::getSize()
{
    return n_elem;
}

void MancalaSolver::print()
{
    Pit* p = head;
    if (p == nullptr)
        std::cout << "{ empty list }" << std::endl;
    else
    {
        std::cout << "{";
        while (p != nullptr)
        {
            std::cout << p->num_pieces;
            if (p->next != nullptr)
                std::cout << " ";
            p = p->next; //move forward in the list
        }
        std::cout << "}" << std::endl;
    }
}

/*
 * The "cm" functions and everything else listed below are for drawing the list in the graphics interface.
 * Do not edit these functions. If they cause crashes it is likely because the linked list was not updated correctly.
 */
void MancalaSolver::cmBegin()
{
    cm_current = head;
}
void MancalaSolver::cmNext(int *idx, int *num_pieces)
{
    if (cm_current != nullptr)
    {
        *idx = cm_current->index;
        *num_pieces = cm_current->num_pieces;
        cm_current = cm_current->next; //go to the next item in the list
    }
}
bool MancalaSolver::cmAtEnd()
{
    return (cm_current == nullptr);
}
