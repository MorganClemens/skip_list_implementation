# Skip List

In this project I will attempt to implement my own _Skip List_ based on a _Linked List_. 

A linked list is a fundamental data structure and can be used to implement other common data structures such as a skip list.  It represents a linear collection of data items whose order is not given by their physical placement in memory.  While an array keeps a linear set of items in order in contiguous memory order, a _Linked List_ has each item in the list _point_ to the next. The _Linked List_ is a data structure consisting of a collection of nodes (objects) which together represent a sequence. 

A _Skip List_ allows faster traversal of a list by compiling sevaral different _Linked Lists_ with varying granularity with respect to the number of nodes visited. At the base level all nodes may be visited while at higher levels fewer and fewer nodes are visited during each traversal of the list. 


## Objectives

* Use pointers to manage an ordered set of data objects
* Manually allocate and reclaim memory used by those pointers
* Understand the complexity of inserting, deleting, and traversing a Linked List.
* Leverage a _Linked List_ to construct a _Skip List_ of ordered items by priority.