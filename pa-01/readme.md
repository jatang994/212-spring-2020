## Programming Assignment 01 (2/18)

This assignment is focused on _Dynamic Arrays_ (resizable arrays). The assignment is worth a total of 100 points. If you have any questions or need any help, please visit us during office hours and/or post questions on Piazza.

> If you need to post any of your actual source code on Piazza for any reason, **please** be sure to tag the post as being *visible to instructors only*, so that you don't inadvertently share code with others and violate class rules.

### Arrays
-----
Arrays are one of the most common and versatile data structures and are essential to almost any useful C or C++ program. They allow us to store hundreds, or even thousands, of elements inside of memory while providing random access in `O(1)` to all of them. While these helpful structures provide us with near-instant access to our data whenever we need it, they are not without weakness. When using regular C-style arrays, you must declare a fixed size for them at the time of their creation and, once this size is declared, it cannot be changed.
```C++
// this array is limited to a maximum of 100 elements, it CANNOT hold more
int myArray[100];
// this array is dynamically *allocated* but its size is still static
int *myOtherArray = new int[100];
```
This presents an obvious problem: What if you don't know how much space you need in your array at compile time? On one hand, if you declare an array with too little space, you will have nowhere to store additional values. On the other hand, if you always declare an array with maximum capacity (e.g. `ULLONG_MAX` equal to 18446744073709551615) you will almost certainly have enough space, but you will be wasting huge amounts of unused memory in almost any situation.

As it turns out, the solution to the problem of capacity is to use *Dynamic Arrays*.

### Dynamic Arrays (Resizable Arrays)
-----
Dynamic Arrays are similar to regular C++ arrays in that they still provide random access in constant time to to elements. However, Dynamic Arrays have the advantage of being **dynamically resizable**. This means that they can grow as you add more elements to them and shrink as you no longer need space. Using a Dynamic Array, you don't need to know the size of a list at compile time.

>If you have programmed previously, chances are you are already familiar with data structures that implement the same idea as dynamic arrays in one language or another. C++ provides an implementation `std::vector<>`. Java's implementation is called an `ArrayList<>`, and Python allows the creation of `list` objects.

The goal of this assignment is to implement your own Dynamic Array Class in C++.

### Code Handout
-----
In order to implement your own class, we are providing starter code (both files can be found inside the `gui/` folder). You will be given a *header file* (`DynamicArray.h`) and a partially-implemented *source file* (`DynamicArray.cpp`) for a class `DynamicArray`.

```C++
#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <string>

class DynamicArray {
    private:
        // the number of items currently in the array
        unsigned int m_length; 
        // the number of available spaces in the array
        unsigned int m_capacity; 
        // the scaling factor when resizing the array (always > 1)
        double m_scaling_factor; 
        // pointer to the array of integers
        int *m_data; 

    public:
        // default constructor, capacity = 0, no need to allocate an internal array yet
        DynamicArray(); 
        // default constructor with a scaling factor, creates an array with capacity = capacity
        DynamicArray(double scaling_factor, unsigned int capacity); 
        // fill constructor, creates an array of capacity = length, and set all values to `default_value`
        DynamicArray(double scaling_factor, unsigned int length, int default_value); 
        // copy constructor
        DynamicArray(const DynamicArray& other); 
        // default destructor, free memory of the array here
        ~DynamicArray(); 

        // get the number of elements in the array
        unsigned int getLength(); 
        // get the capacity of the array
        unsigned int getCapacity();
        // get scaling factor Needed by GUI 
        double getScalingFactor();
        // set the scaling factor of the array
        void setScalingFactor(double value); 
        // convert the vector into a printable string 
        std::string toString(); 

        // find the first occurrence of "value" in the array. Return false if the value is not found
        // [10 points if correct]
        bool findFirstOf(int value, unsigned int* index);
        // find the last occurrence of "value" in the array. Return false if the value is not found
        // [10 points if correct] 
        bool findLastOf(int value, unsigned int* index); 

        // add a value to the end of the array (resize if necessary)
        // [10 points if correct] 
        void append(int value); 
        // add a value to the beginning of the array (resize if necessary)
        // [10 points if correct] 
        void prepend(int value); 
        // remove the last value from the array
        // [10 points if correct] 
        void removeLast(); 
        // remove the first value from the array 
        // [10 points if correct] 
        void removeFirst(); 
        // remove all elements from the array 
        // allocated memory should be deleted and the array pointer should now point to NULL
        // capacity and length should be reset to zero
        // [10 points if correct] 
        void clear(); 

        // overloading the [] operator for read/write access
        int& operator[](unsigned int index); 
        // assignment operator
        DynamicArray& operator=(const DynamicArray &other); 
};

#endif
```

Some functions have already been implemented for you inside of the `DynamicArray.cpp` file. The rest of the functions are up to you to implement, specifically where you see `// TODO` comments. You may add your own _private_ functions should you wish.

>Note: You are _not_ allowed to alter any of the given private variables, public function signatures or implementations.

### Pair Programming
-----
For this assignment, you are __required__ to choose a *single* partner **from your lab section** with whom you will work to complete the assignment. We feel that this will be a good chance, not only to experience pair programming (which is often mandated in upper level CS courses), but to hopefully gain knowledge by working with someone else.

> Note: You should **not** simply split up the assignment into separate parts for each partner. For any given part of the assignment, both partners must be able to understand and explain design choices and functionality.

When you submit your code, please make sure to submit together to Gradescope as a group. You may **not** share your code with others outside your group.

### Code Interviews
-----
For this assignment part of your grade will be a code interview where you will sit with a TA. You will explain how your code works and why you made certain decisions, as well as answer some questions. These interviews will account for `30%` of your final grade; the other `70%` will be based on the functional correctness and quality of your code.

This grading scheme is meant to make sure not only that your code works functionally, but also that you understand why it works. If you understand your code and the problem but don't have perfectly functional code, this is a chance for you to get a better grade. If, on the other hand, your code is functionally perfect but you don't understand it, you may be penalized.

### GUI Component
-----
Our TA Chris has taken some time to create a graphical component for this project using [Qt Creator](https://www.qt.io/product) (environment and libraries for UI development). This will allow you to visualize your code once you have it working. Please follow the [instructions to install Qt Creator](./qt.md) on your computer.

Remind that your primary goal on this assignment is to develop a correct implementation of the class `DynamicArray`.  You can fully test your implementation using a console based driver (you can find an example of this driver inside the `gui` folder, named `main_tester.cpp`).  The graphical inferface is just another way to verify the correctness of your solution.  If you want to have and idea of how the GUI should look with a correct implementation of `DynamicArray` watch this video https://www.youtube.com/watch?v=5iiZ4Wz2ylQ.

### Submission and Grading
---
To submit your solution to [Gradescope](http://gradescope.com), simply select `DynamicArray.cpp` and `DynamicArray.h` then use the *drag and drop* option.  You will not receive immediate feedback on the functionality of your program so be sure to test it locally and make sure it works (we can assist with this in office hours).

> You must be reminded that students caught cheating or plagiarizing will receive `no credit`. Additional actions, including a failing grade in the class or referring the case for disciplinary action, may also be taken.
