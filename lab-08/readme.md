# Lab 8 - Sets and Maps

## 1. Introduction
In this lab we will be looking into how to store data read from text files into sets and maps, both of which can be thought of as using binary search trees in their implementations. We will be manipulating classes from the STL (Standard Template Library) such as fstream, set and map. The goal of this lab will be to become familiar with use cases of set and map, their operations and to understand the underlying data structures that make them tick.


## 2. Reading from Files
Here are the steps required for handling a file for input:
<ol start="1">
    <li>Create an instance of ifstream.</li>
    <li> Open the file. (Check for failure to open.)</li>
    <li>Read from the file.</li>
    <li>Close the file.</li>
</ol>

Example of using ifstream:
```C++
#include <iostream>
#include <fstream>
int main() {
    std::string line;
    std::ifstream table;                // 1. Create instance
    table.open("tabledata");                    // 2. Open the file
    if(table.fail()){                           //    Check open
        cerr << "Can't open tabledata\n";
        return 1;
    }
    while(std::getline(table, line)){           // 3. get a line of data from table, store in string

    }    
    table.close();                                  // 4. Close the file
    // ...
}
```

## 3. Sets

The reason for being called a "set" comes directly from set theory, a branch of mathematics, in which a set is a collection of distinct objects. In other words, each element that could be in the set is either in the set or not in the set, there is no "amount" associated with a given element.  There are a myriad of operations that you can perform on a set. Look at the site below on sets to familiarize yourself with the basic operations.
[set reference](http://en.cppreference.com/w/cpp/container/set)

```C++
#include <set>
#include <string>

int main() {
    std::set<std::string> animals; // creating a set of strings
	
	myset.insert("cat");
	myset.insert("dog");
	myset.insert("horse");
	
	// ...
}

```
## 4. Maps

Maps are similar to sets, in that each contains a number of unique elements that are in order. The *key* difference between sets and maps in general is that sets store elements all by themselves, whereas maps store *key-value pairs*. A key-value pair is a pair of two elements where the first element, the key, is used to index the map, and the second element, the value, is what is stored/returned. 

Here is an example of maps in action:
```C++
#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> mymap;

    mymap["dog"] = 7;
    mymap.emplace("cat", 4); // This is the same as mymap["cat"] = 4
    mymap.insert({{"fish", 11}}); // This is the same as mymap["fish"] = 11
    mymap["cat"]++;

    std::cout << mymap["dog"] << std::endl; // Prints 7
    std::cout << mymap["cat"] << std::endl; // Prints 5
    std::cout << mymap["fish"] << std::endl; // Prints 11

}
```
Note that when you use `emplace` or `insert` with a key that is *already in the map*, the value will **not** be replaced.

## 5.0 Task for Today

You will be working with a database containing information on cases of COVID-19. The goal of this task is to read through the provided text file, insert each unique country into a set and then insert key-value pairs of states/provinces and their associated **confirmed** COVID-19 cases into a map. States/provinces will be the key, and confirmed cases will be the value. If a line of of the text file **does not** have an associated state/province, then **use** the country as the key.

The data base is comma-separated; the first column of data is the state/province where the COVID-19 cases are occurring. The second column of data is the country and the current confirmed cases of COVID-19 will be the final column of data. Every row has a country name and the same number of commas, but not every row has a state/province.

### 5.1 Starter Code

You will be given lab-08.cpp, and confirmed_cases.txt (database of confirmed COVID-19 cases), fill in the required functions and test if your code is correct by running the program. The program will output "All tests passed" if everything checks out. There is also a marked space in the main to create any custom tests you may think of. It is recommended that you create custom tests to ensure that your individual functions are correct as well as to answer some of the questinons below.

### 5.2 Questions

Create a text file called lab-08.txt and provide the answers to the following questions:

<ol start="1">
    <li>What is the big O runtime of insert on a set? A map?</li>
    <li>What is the difference between a set and a map? </li>
    <li>Why are sets and maps useful? </li>
    <li>How many countries currently have confirmed cases of COVID-19? (set methods)</li>
    <li>How many confirmed cases does Macau, China currently have? (map methods)</li>
    <li>Which country has the most confirmed cases?</li>

</ol>

## 6. Submission

You will submit your lab-08.cpp and lab-08.txt files to Gradescope and include any group members you worked with in your submission. If working in a group, only one person needs to submit, but it is recommended that you complete your own local version of the lab for your own benefit.
