#ifndef _LAB_5_
#define _LAB_5_


class Queue{
    // You will need to add your own private data members
    // depending on the type of implementation chosen by
    // your group.
    private:

    public:
    // Default constructor
    Queue();

    // Destructor
    ~Queue();

    // Enqueue should insert an element at the back of the queue.
    void enqueue(int n);

    // Dequeue should remove an element from the front of the queue.
    int dequeue();

    // Front will return the value of the element at the front of the queue.
    int front();

    // Size will return the size of the queue.
    int size();

    // Empty returns true if the queue is empty and false otherwise.
    bool empty();

};
#endif