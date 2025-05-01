#include "SkipList.h"
#include <iostream>
#include <random> // For random number generation

// SkipNode constructor
SkipNode::SkipNode(int d, int level) {
    data = d;
    node_level = level;
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
SkipNode* SkipList::init_SkipNode(int data, int level) {
    SkipNode* node = new SkipNode(data, level);
    return node;
}

// Insert a value into the skip list (Handle random level).
bool SkipList::insert(int data) {
    std::vector<SkipNode*> update(max_level, nullptr); // track nodes we'll need to update later
    SkipNode* current = head;

    // Traverse list and record update points
    for (int i = current_level - 1; i >= 0; i--) {
        while (current->forward[i] != nullptr && current->forward[i]->data < data) {
            // Allows us to move to the right and down in one loop
            current = current->forward[i];
        }
        update[i] = current; // record last node before insert (to be updated later)
    }

    // Exception: duplicate node exists (not allowed)
    SkipNode* next = current->forward[0]; // record next node
    if (next != nullptr && next->data == data) {
        return false; // no duplicate insertion
    }

    // Generate and update head levels
    int new_level = randomLevel();

    if (new_level > current_level) {
        for (int i = current_level; i < new_level; i++) {
            update[i] = head; // queue head to be updated
        }
        current_level = new_level;
    }

    // Build node
    SkipNode* new_node = init_SkipNode(data, new_level);

    // Insert and update
    for (int i = 0; i < new_level; i++) {
        new_node->forward[i] = update[i]->forward[i];
        update[i]->forward[i] = new_node;
    }

    return true;
}

// Find location of value in SkipList.
SkipNode* SkipList::find(int data) {
    // Traverse the list
    SkipNode* current = head;

    for (int i = current_level - 1; i >= 0; i--) {
        while (current->forward[i] != nullptr && current->forward[i]->data < data) {
            // Allows us to move to the right and down in one loop
            current = current->forward[i];
        }
    }

    // Determine if next node is correct node
    SkipNode* next = current->forward[0]; // record next node
    if (next != nullptr && next->data == data) {
        return next; // return found node
    }

    return nullptr;
}

// Removes the node indicated by the given data and frees up memory.
bool SkipList::remove(int data) {
    std::vector<SkipNode*> update(max_level, nullptr); // track nodes we'll need to update later
    SkipNode* current = head;

    // Traverse list and record update points
    for (int i = current_level - 1; i >= 0; i--) {
        while (current->forward[i] != nullptr && current->forward[i]->data < data) {
            // Allows us to move to the right and down in one loop
            current = current->forward[i];
        }
        update[i] = current; // record last node before removal (to be updated later)
    }

    // Exception: node is not in list
    SkipNode* target = current->forward[0];
    if (target == nullptr || target->data != data) {
        return false; // not found
    }

    // Bypass target node in all levels where it exists
    for (int i = 0; i < target->node_level; i++) {
        if (update[i]->forward[i] == target) {
            update[i]->forward[i] = target->forward[i];
        }
    }

    // Delete node from memory
    delete target;

    // Adjust current level (if needed)
    // Finds at which levels current_level points to nothing 
    // (Means deleted node was highest level node)
    while (current_level > 0 && head->forward[current_level] - 1 == nullptr) {
        current_level--;
    }

    return true;
}

// Prints all levels of Skip List starting with the highest level.
void SkipList::display() {
    cout << "\n_______ Skip List _______\n";
    // Traverse and print
    for (int i = current_level -1; i >= 0; i--) {
        SkipNode* current = head->forward[i]; // reset head after breaking from while loop
        cout << "Level " << i + 1 << ": ";
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->forward[i];
        }
        cout << "nullptr" << endl; // breaking from while loop means we found a nullptr
    }
}

// Randomly decides the height of new nodes.
int SkipList::randomLevel() {
    // Random number generation
    std::random_device rd;     // Non-deterministic seed
    std::mt19937 gen(rd());    // Mersenne Twister engine
    std::uniform_real_distribution<> dist(0.0, 1.0); // From 0-1

    int level = 1; 
    while (dist(gen) < probability && level < max_level) {
        level++;
    }

    return level;
}
