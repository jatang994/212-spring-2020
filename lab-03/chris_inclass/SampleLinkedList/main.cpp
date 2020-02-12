#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList my_list = LinkedList();

    my_list.append(2.0);
    my_list.append(8.5);
    my_list.append(40.0);
    my_list.print();

    return 0;
}
