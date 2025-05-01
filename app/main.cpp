#include <iostream>
#include "../code/SkipList.h"

using namespace std;

int main() {
    // Test the functions here

    // Debug randomLevel
    SkipList test1;
    test1.insert(25);
    test1.insert(34);
    test1.insert(15);
    test1.insert(26);
    test1.insert(100);
    test1.display();

    return 0;
}