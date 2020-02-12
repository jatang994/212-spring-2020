#ifndef MANCALASOLVER_H
#define MANCALASOLVER_H

#ifndef NULL
#define NULL 0x00
#endif

class Pit; //forward declaration of Pit

class MancalaSolver
{
private:
    Pit* head;
    Pit* curr; //cjm: this was in the lab from last spring semester but I don't think we need it this time around
    Pit* tail; //cjm: I added this because I did not want to iterate through the entire list everytime I wanted to add something
    unsigned int n_elem;

public:
    MancalaSolver();
    ~MancalaSolver();

    int removeByIndex(unsigned int idx);

    void append(int idx, int num_pieces);

    int solve(int idx);

    unsigned int getSize();
    void print();

    /*
     * The "cm" functions and everything else listed below are for drawing the list in the graphics interface.
     * Do not edit these functions. If they cause crashes it is likely because the linked list was not updated correctly.
     */

public:
    void cmBegin();
    void cmNext(int* idx, int* num_pieces);
    bool cmAtEnd();

private:
    Pit* cm_current;
};

#endif // MANCALASOLVER_H
