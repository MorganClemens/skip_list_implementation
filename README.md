# SkipList Implementation in C++


An efficient C++ implementation of a Skip List data structure supporting fast insertion, search, and deletion operations with probabilistic balancing.


A linked list is a fundamental data structure and can be used to implement other common data structures such as a _Skip List_.  It represents a linear collection of data items whose order is not given by their physical placement in memory.  While an array keeps a linear set of items in order in contiguous memory order, a _Linked List_ has each item in the list _point_ to the next. The _Linked List_ is a data structure consisting of a collection of nodes (objects) which together represent a sequence. 

A _Skip List_ allows faster traversal of a list by compiling sevaral different _Linked Lists_ with varying granularity with respect to the number of nodes. At the base level all nodes may be visited while at higher levels fewer and fewer nodes are visited during each traversal of the list. 


## Objectives

* Use pointers to manage an ordered set of data objects.
* Manually allocate and reclaim memory used by those pointers.
* Understand the complexity of inserting, deleting, and traversing a Linked List.
* Leverage a _Linked List_ to construct a _Skip List_ of ordered items by priority.

## Features
* Insert integers into the Skip List
* Search for values
* Remove Values
* Print the structure level by level
* Use probabilistic height assignment (0.5) for balancing
* Max level set to 4


## How to Build and Run the Project

### Prerequisites
* C++11 or later
* g++ or another compatible C++ compiler

### Build
```bash
g++ main.cpp SkipList.cpp -o skiplist
```

### Usage

In this example, I'll add a few numbers to the list, display the structure, remove an element, and display the structure again. 

```C++
SkipList* test1 = new SkipList(); // New object
    test1->insert(25);
    test1->insert(34);
    test1->insert(15);
    test1->insert(26);
    test1->insert(100);
    test1->display();
    test1->remove(25);
    test1->display();

    delete test1; // Free memory
```
Output:
```bash

_______ Skip List _______
Level 2: 15 -> 25 -> nullptr
Level 1: 15 -> 25 -> 26 -> 34 -> 100 -> nullptr

_______ Skip List _______
Level 2: 15 -> nullptr
Level 1: 15 -> 26 -> 34 -> 100 -> nullptr

```

### Project Structure
* `main.cpp` — entry point and test functions
* `SkipList.h` — class declarations
* `SkipList.cpp` — method definitions

## License
MIT License. See `LICENSE` file for details.

## Author

[[Morgan](https://github.com/MorganClemens)]

