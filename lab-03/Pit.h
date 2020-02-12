#ifndef PIT_H
#define PIT_H

class Pit
{
private:
    Pit* next;
    int index;
    int num_pieces;

public:
    Pit(int idx, int pieces);
    ~Pit();

    friend class MancalaSolver;

};

#endif // PIT_H
