#include <iostream>
#include "queue.cpp"

int main(){

    // TEST CASE #1
    Queue myQueue;

    // Testing Enqueue 
    for(int i = 1 ; i <= 1000 ; ++i) {
        myQueue.enqueue(i);
    }

    if(myQueue.front() != 1) {
        std::cout << "Test case #1: Enqueue Failed: wrong front element" <<std::endl;
        return 1;
    }

    if(myQueue.size() != 1000) {
        std::cout << "Test case #1: Enqueue Failed: not enough elements" << std::endl;
        return 1;
    }

    if(myQueue.empty()) {
        std::cout << "Test case #1: Enqueue Failed: empty is true" << std::endl;
        return 1;
    }

    // Testing Dequeue
    for(int i = 1 ; i <= 1000 ; ++i) {
        int x = myQueue.dequeue();
        if (x != i) {
            std::cout << "Test case #1: Dequeue Failed: wrong value: " << x << " != " << i << std::endl;
            return 1;
        }

        if(myQueue.size() != 1000 - i) {
            std::cout << "Test case #1: Dequeue Failed: wrong size" << std::endl;
            return 1;
        }
    }

    if (!myQueue.empty()){
        std::cout << "Test case #1: Empty Failed." << std::endl;
        return 1;
    }

    if (myQueue.size() != 0){
        std::cout << "Test case #1: Size Failed." << std::endl;
        return 1;
    }


    // TEST CASE #2
    Queue q2;

    for(int i = 1 ; i <= 1000 ; i++) {
        for(int j = 1 ; j <= 10 ; j++) {
            q2.enqueue(j);
        }

        
        for(int j = 2 ; j <= 10 ; j++) {
            q2.dequeue();
        }

        if (q2.size() != i){
            std::cout << "Test case #2: Dequeue Failed." << std::endl;
            return 1;
        }
    }

    if (q2.size() != 1000){
        std::cout << "Test case #2: Size Failed: queue not correct size" << std::endl;
        return 1;
    }

    std::cout << "Passed all tests." << std::endl;
    return 0;
}