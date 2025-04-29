#pragma once // protect against being duplicated

#include <memory>
#include <string>

using namespace std;

struct SkipNode {
    int data; // value of this node
    vector<SkipNode>* forward; // vector of pointers at different levels, null if last node in the list
};

class SkipList {
public:
    SkipList(); // Constructor
    ~SkipList(); // Deconstructor

    // Creates a new SkipNode struct from heap and. Stores the passed integer and
    // all forward pointers point to null.
    // Returns a pointer to the new SkipNode. 
    SkipNode* init_SkipNode(int data, int level);

    // Insert a value into the skip list (Handle random level).
    // Returns true if finished successfully
    bool insert(int data);

    // Find if a value exists
    // Returns node address of data, null otherwise
    SkipNode* find(int data);

    // Removes the node indicated by the given data and frees the memory
    // If an invalid offset is given, the function returns false and has no effect.
    // Returns true if successful, false otherwise
    bool remove(int data);

    // Prints all levels of the skip list starting with the highest level.
    // No return value.
    void display();

    // Randomly decides the height of new nodes.
    int randomLevel();



private:
    // Add private member variables here
    int max_level;          // max number of levels
    float probability;      // probability of promoting a node (0.5)
    int current_level;      // highest level in the list
    SkipNode* head;         // pointer to the head of list
};