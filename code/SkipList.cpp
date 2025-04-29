#include "SkipList.h"

#include <cstdlib> // For rand()

// SkipNode constructor
SkipNode::SkipNode(int d, int level) {
    data = d;
    forward = vector<SkipNode*>(level, nullptr); 
}


// Constructor initializes values and creates a dummy head node.
SkipList::SkipList() {
    max_level = 4;      // max allowed level
    probability = 0.5;  // 50% chance to promote
    current_level = 0;  // start at base level
    head = init_SkipNode(-1, max_level); // Dummy head with max height.
}

// Deconstructor properly walks and deletes nodes at each level.
// (Would just deleting the base level work?).
SkipList::~SkipList() {
    // TODO: walk and delete each node.
}

// Create new SkipNode struct from heap memory.
SkipNode* init_SkipNode(int data, int level) {
    SkipNode* node = new SkipNode(data, level);
    return node;
}

// Insert a value into the skip list (Handle random level).
bool insert(int data) {

    // TODO
}

// Find location of value in SkipList.
SkipNode* find(int data) {

    // TODO
}

// Removes the node indicated by the given data and frees up memory.
bool remove(int data) {

    // TODO
}

// Prints all levels of Skip List starting with the highest level.
void display() {

    // TODO
}

// Randomly decides the height of new nodes.
int randomLevel() {

    // TODO
}
