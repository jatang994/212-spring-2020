#include <iostream>
#include <ctime>
#include "DynamicArray.h"

using namespace std;

int main(int argc, char** argv)
{
    const int length = 20, range = 100;
    int i, rc = 0, x, index;
    double scaling_factor = 0.5;
    DynamicArray da;

    /*
     * seed the random number generator using the system clock this prevents
     * the computer from using the same random sequence of numbers over and over again
     */
    srand(static_cast<unsigned int>(time(nullptr)));

    cout << "---- Testing the constructor using a scaling factor of " << scaling_factor << " ----" << endl;
    da = DynamicArray(scaling_factor, 10);
    cout << "Printing empty array" << endl;
    cout << "ARRAY: " << da.toString() << endl;

    cout << "---- Testing the ability to add values to the array ----" << endl;
    for (i = 0; i < length; i++)
    {
        x = rand() % range;
        cout << "Adding value " << x << endl;
        da.append(x);
        cout << "ARRAY: " << da.toString() << endl;
    }
    cout << "ARRAY: length=" << da.getLength() << " capacity=" << da.getCapacity() << endl;

    cout << "---- Testing the ability to modify values in the array ----" << endl;

    for (i = 0; i < 5; i++)
    {
        index = rand() % length;
        x = rand() % range;
        cout << "Changing value at index " << index << " to value " << x << endl;
        da[index] = x;
        cout << "ARRAY: value at " << index << " equals " << da[index] << endl;
    }

    cout << "---- Clearing array ----" << endl;
    da.clear();
    cout << "ARRAY: length=" << da.getLength() << " capacity=" << da.getCapacity() << endl;
    cout << "ARRAY: " << da.toString() << endl;

    return rc;
}
