# Lab 10: #hashtable spel checkinng

## 1. Introduction

In today's lab we will be spell checking large text files using Hash Tables.
This may seem like a tall order at first, but wait - it's not going to be all that bad, we will be using someone else's implementation.
Specifically we will use the classes [`unordered_set`](http://en.cppreference.com/w/cpp/container/unordered_set) and [`unordered_map`](https://en.cppreference.com/w/cpp/container/unordered_map)which are both provided in the C++11 Standard Template Library (or STL). 

## 2. Hash Tables

The first implementation we will look at is an `unordered_set`, with an emphasis on *unordered*.
Think about a hash table; are the elements stored in a specific order? 
No, they are not - and as such, you cannot read the elements from low to high without a lot of extra work.
Together these elements make up what is called a set, thus named because in set theory (a branch of mathematics), a set is an unordered collection of distinct objects.

Sets are not allowed to contain duplicates, meaning there can only ever be one of any given element in a set.
The linked reference on unordered sets below suggests that they are typically implemented using hash tables with separate chaining.
There are a myriad of operations that you can perform on a set, all of which are detailed in the site linked below.
You should check out the site below to familiarize yourself with the basic operations, as you will need to know how to use an `unordered_set` in order to successfully complete today's lab.
Look at the site below on sets to familiarize yourself with the basic operations.

[Unordered Sets (reference)](http://en.cppreference.com/w/cpp/container/unordered_set)

### 2.1 Example

Here is a basic example of creating an `unordered_set`:

```C++
#include <unordered_set>
#include <string>

int main()
{
	std::unordered_set<std::string> myset; // creating a set of strings
	
	myset.insert("cat");
	myset.insert("dog");
	myset.insert("horse");
	
	// ...
}

```

Congrats! You just made a Hash Table!
<p><img src="http://www.staples-3p.com/s7/is/image/Staples/s0105150_sc7?$splssku$" width="144"></p>

Notice that the `unordered_set` here is initialized with a data type between angle brackets, in this case `std::string`, similar to how an instance of `vector` is initialized. This is because an instance of `unordered set`, (and `set`, as you will see later), can only hold elements of a single data type, and so it needs to know what that data type will be when it is created. This is contrary to the mathematical set, which has no restrictions on what it may contain.

### 2.2 Conditions for Creation

The `unordered_set` class provides a lot of really nice functionality, so you might decide that you want to start using `unordered_set` for everything: an unordered set of integers, an unordered set of strings, an unordered set of `BSTree` instances...wait, what? Compilation error?

That's right. Unlike the `vector` class, there are actually restrictions on what data types you're allowed to use when creating an `unordered_set`. This is because an `unordered_set` needs to know certain things about its data type in order to function correctly. Earlier you were told that the class is implemented using a hash table, but one of the key features of a hash table is its *hash function*. On a basic level, this is a function that takes some data and spits out an array index, determining where the data can be stored. For all good hash functions, this index should be approximately unique, i.e. two different inputs should almost never give the same index. This is important to know about because an object can only be put into an `unordered_set` if it knows how to hash the object. The C++ language provides default hash functions for many common data types, such as `int` and `string`, but for more complex data types, or ones you create yourself, there is no default way to hash them. Unless you create a custom hash function, which is beyond the scope of this class, you cannot use an `unordered_set` with those default-less data types.

If that didn't ruin your fun, it actually gets just a bit worse. Not only does an `unordered_set` need to know how to hash an object, it also needs to know how to determine if two objects are *equal*. Again, for most basic data types, this is no problem at all, but if you want to use an `unordered_set` on a class you created and you even wrote your own hash function for it, you *still* need an `equal_to()` function if you want your code to compile.

To give a concrete example of these concepts, consider the following lines (assuming `bstree.h` has been included):

```c++
std::unordered_set<string> A;
std::unordered_set<BSTree> B;
```

Since C++ knows exactly how to compare and hash strings, (otherwise the previous example would be pretty silly), the first line will cause no problems during compilation. On the other hand, `BSTree` is a new class, not previously known to C++, and so C++ knows neither how to compare two instances of `BSTree` nor how to hash one. The result will be a compilation error.

> Note: Just because a class is defined in a C++ library does not mean it's hashable or comparable.

 

## 3. Unordered maps

The `unordered_map` class is similar to `unordered_set` respectively, in that each contains a number of unique elements, and they are both implemented as hash tables. The *key* difference between the two is something you learned about in lab 8 on `set` and `map`: `unordered_set` stores its elements by themselves, whereas `unordered_map` stores *key-value pairs*. A key-value pair is a pair of two elements where the first element, the key, is used to index the map, and the second element, the value, is what is stored/returned. The key is **always** *unique*, meaning there cannot be more than one of the same key in a map. However, the same value could be mapped to different keys. If you have ever written a Python program using dictionaries, then you've actually already used unordered maps before!

Key-value pairs are also abundant in your every day lives. Your student IDs could be considered a **key**, a unique identifier of you as a student. Your student ID associates you with your student information, which is to say that your information is the **value** in the key-value pair relationship.
The same could also be said for a username on a website; the username is the key and the user information the value.

### 3.1 Example

Here is an example of unordered maps in action:

```C++
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> mymap;

    mymap["dog"] = 7;
    mymap.emplace("cat", 4); // This is the same as mymap["cat"] = 4
    mymap.insert("fish", 11); // This is the same as mymap["fish"] = 11
    mymap["cat"]++;

    std::cout << mymap["dog"] << std::endl; // Prints 7
    std::cout << mymap["cat"] << std::endl; // Prints 5
    std::cout << mymap["fish"] << std::endl; // Prints 11

}
```

Note that when you use `emplace` or `insert` with a key that is *already in the map*, the value will **not** be replaced.

### 3.2 Conditions for Creation

By now you've seen that `unordered_set` has certain requirements for what types of objects it is allowed to store.
It might seem like `unordered_map` must then be even worse, since each takes *two* classes instead of one.
However, the requirements are actually precisely as simple as those of `set` and `unordered_set`.
This is because the key class follows the same rules as the set-based counterpart and there are no restrictions on what the value class is allowed to be.
If you have already created `hash` and `equal_to` functions for your `BSTree`, you can go ahead and use it as the key class for your `unordered_map`.  

## 4. Starter Code

The starter code for today's lab may look a bit complicated compared to some previous labs, especially considering how many C++ libraries are being used, so let's break it down bit-by-bit.

### 4.1 The Helper Functions

This lab contains the following two helper functions:

```c++
void remove_punctuation(std::string* s) {
	int i = 0;
	while (i < s->length()) {
		if (((*s)[i] >= 'A' && (*s)[i] <= 'Z') || ((*s)[i] >= 'a' && (*s)[i] <= 'z') || ((*s)[i] >= '0' && (*s)[i] <= '9')) {
			i++;
		} else {
			s->erase(i, 1);
		}
	}
}
void to_lower(std::string* s) {
	for (int i = 0; i < s->length(); i++) {
		if ((*s)[i] >= 'A' && (*s)[i] <= 'Z') {
			(*s)[i] += 'a' - 'A';
		}
	}
}
```

The purpose of these functions should be fairly clear based on the function names, but pay special attention to the parameter and return type. Each of these functions will take a *pointer* to a `string` and modify it *in-place*. All you need to do is pass in a valid pointer to an instance of `string` and call the function, and the `string` will be modified.

**When working on the lab, you must call these two functions on each word read in from a file before using it.**

### 4.2 Functions You Will Implement Today

Below is a description of each of the functions you will be implementing today. There are two separate functions you will work on (`spell_check_hash_table` and `find_letter_frequencies`).
You will also be filling out a space in the main function. These descriptions are meant to get you familiarized with the parameters and data types used in each function. In section 5 of the lab instructions we will go into farther detail as to what will need to be done to implement them.

#### 4.2.1 The Spell Check Function

This is the first function you will need to implement, but **not** where you will start the lab.

```c++
void spell_check_hash_table(const std::string& filename,
                            const std::unordered_set<std::string>& dict);

```


The parameters here should seem even stranger than before, but they're not terribly complicated. In these function headers, the `&` symbol at the end of the data types signifies that the objects passed in will be passed by reference. You can pass in an instance of `std::string` or `std::set<std::string>` just as you would with any function, but instead of making a copy of the instance, the actual instance itself will be passed into the function. On the other hand, the `const` keyword essentially states that the function is not allowed to make any modifications to those parameters. This is sensible for these functions as a string literal cannot be modified and we don't want to accidentally change our dictionary.

#### 4.2.2 The Letter Frequencies Function

This is the final function you will need to implement.

```c++
void find_letter_frequencies(const std::string& filename);
```

There isn't much to say here, as you should now understand the parameter, and the actual instructions for implementation will be specified **later**.

#### 4.2.3 The Main Function

The `main()` function is where you will start this lab, but much of the work has already been done for you. The already implemented portions of `main()` take care of calling and timing all functions as necessary, along with creating the `unordered_set` object in the first place. As you will see later, the only place you will need to write code is inside the function's while loop.

There is one detail you should pay attention to, though: the construction of the while loop. If you are still fairly uncomfortable with reading from a file, the while loop here shows one way to do so. Given an input file stream, or `ifstream` object, `std::getline(file, str)` will read an entire line from `file` and write it to `str`, *replacing whatever was there before*, and it will *return zero* if it reaches the end of the file. This means that it is suitable for use in a loop, allowing you to read lines from a file until the end with fairly little effort. **This will become useful to you in implementing this lab**.

### 4.3 One Last Detail

When reading lines from a file, you will also need to get each word in the line. This may seem like a complex task at first, but `istringstream` is here to save the day. It basically lets you treat a `string` as a stream, making the following code valid.

```c++
std::string my_string = "Hello World!";
std::istringstream my_stream(my_string);
std::string first_word;
my_stream >> first_word;
std::cout << first_word << std::endl;
```

In the code snippet above, the fourth line uses the *insertion operator* to read from `my_string` until it reaches a whitespace character, essentially reading a single word from the `my_string` into `first_word`. In fact, an instance of `istringstream` will also return zero if it runs out of characters to read, making it suitable for use in a loop as well.

## 5. Instructions

### 5.1 Acquiring the Data

Your job today is to write a program to determine whether each word in each of three books is in a dictionary.
You can download the books using the `getbooks.sh` script that we have provided using the following command:

```bash
$ source getbooks.sh
```

Now that you have the books, all you need is the dictionary.
We will also be comparing against the words that are part of your Docker image's built-in dictionary.
To acquire the dictionary file, all you need to do is enter the directory with all of your files for this lab and run:

```bash
$ cp /usr/share/dict/american-english .
```

You should now have a list of American English words with which you can complete this lab's task.

**In the case that you aren't using Docker**, you may use the included `american-english` file instead.

### 5.2 Implementing the Algorithms

The programming portion of this lab is split into three tasks:

#### 5.2.1 Read the Words from the Dictionary

The first thing you must do is read all of the words in the `american-english` file into the `unordered_set` object , named `dict_ht` respectively.
This should be done within the loop in `main()`.
The steps to accomplish this task are simple:

1. Use `remove_punctuation()` and `to_lower()` to "normalize" `token`
2. Insert each normalized token into the hash table `dict_ht`

#### 5.2.2 Spell-Check Each Book

Once `dict_ht` has been filled with words, you must then read each of the books and output any words that are not spelled correctly.
To accomplish this, the program will call `spell_check_hash_table()` on each of the three file names.
You must then implement the two `spell_check_` functions such that they perform the following steps:

1. Open the file given by `filename` using `ifstream`
2. Iterate through file using `getline` (see the loop in `main()` for an example)
3. For each line in the file, split the line into words using `istringstream`
    1. For each word in the line, use `remove_punctuation()` and `to_lower()` to normalize the word
    2. Check if the normalized word is in `dict`. If not, print the word to STDOUT

Note: If you find that one of the books contains a lot of misspelled words, you might want to redirect your output to a file.
You can do this by adding `> FILE_NAME.txt` to the end of the compile line in the `makefile`.

Once you have completed this section, you should be able to run your program and see how long each function took.
You should then be able to answer the set questions in Section 6.3.

#### 5.2.3 A Bit of Cryptography

Finally, you will implement `find_letter_frequencies`. 

In the field of cryptography and code breaking, it is sometimes helpful to know how often a word will start with a given letter.
Simply looking at the first letter of each word in the dictionary is insufficient, as the distribution of words is fairly even amongst all existing words.
However, a book provides a much more realistic representation of how often a word will start with a given letter in normal use.
Your goal for this task is to use an `unordered_map` to determine how many words in each of the three books start with **each** letter, along with what percent of words started with that letter. This is to say that you will need to find and print the frequency for which each word in a book **begins** with each letter in the english alphabet (a-z).
Your print statement *may* be something similar to the following:

```C++
std::cout << "The letter " << let << " appears " << amt << " time(s), which is " percent "% of all the words." << std::endl;
```

Where `let`, `amt` and `percent` represent the actual letter, the amount of words that start with that letter, and the percent of words that start with that letter respectively.
Be sure to print each percent as a `double` to ensure more accurate results.

Example output:
```C++
The letter a appears 46 time(s), which is 5.37% of all the words.
The letter b appears 35 time(s), which is 3.12% of all the words.
The letter c appears 25 time(s), which is 2.43% of all the words.
The letter d appears 23 time(s), which is 2.36% of all the words.
The Letter e appears 86 time(s), which is 7.21% of all the words.
The Letter f appears 72 time(s), which is 6.81% of all the words.
.
.
.
(and so on)
```
### 5.3 Answering the Questions

**unordered_set questions:**

<ol>
    <li>What is the time needed to run the spell checker across the three books using an unordered set?</li>
    <li>If the spell checker was implemented using an ordered set, which would be faster(unordered_set or set)? Give one or two reasons for your answer.</li>
</ol>

**unordered_map questions:**

<ol start="3">
    <li>How did the starting letter percents of each word compare between the three books? Why might this be?</li>
    <li>Which starting letter was most common for each of the three books?</li>
</ol>

## 6. Submission

Your submission for this lab will be the `lab-10.cpp` file containing your implementations and a `lab-10.txt` file containing your answers to the above questions.
As always, if you do not finish the programming portion of the lab, submit your source file at the end of the lab as-is.
It is highly recommended that you work in a group and utilize online TA lab sessions.
