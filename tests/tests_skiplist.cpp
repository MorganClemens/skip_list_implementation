#include "../code/SkipList.h"
#include <gtest/gtest.h>
#include <string>
#include <iostream>

using namespace std;

// @@@ I used AI to generate this test file and take no credit for the unit tests built here.
// @@@ I wanted to experiment with unit tests just to see how they're built and run
// @@@ although that was beyond the scope of this project.

class LinkedListTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Code here will run before each test.
    }

    void TearDown() override {
        // Code here will run after each test.
    }

    // Helper to build a three-node list (adjust as needed)
    node* buildThreeNodeList(int a, int b, int c) {
        node* head = new node;
        head->data = a;
        head->next = new node;
        head->next->data = b;
        head->next->next = new node;
        head->next->next->data = c;
        head->next->next->next = nullptr;
        return head;
    }
};

TEST_F(LinkedListTest, InitializationTest) {
    LinkedList list;
    // ASSERT_FALSE(list.getTop()); // Uncomment and adjust after you create getTop()
}

TEST_F(LinkedListTest, ReportTest) {
    LinkedList list;
    // EXPECT_EQ("", list.report()); // Uncomment and adjust after you create report()
}

TEST_F(LinkedListTest, AppendDataTest) {
    LinkedList list;
    node* head = buildThreeNodeList(1, 2, 3);
    // list.setTop(head); // Uncomment after you create setTop()

    // list.appendData(4); // Uncomment after you create appendData()
    // ASSERT_EQ(4, list.getTop()->next->next->next->data); // Adjust after methods ready
}

TEST_F(LinkedListTest, InsertDataTest) {
    LinkedList list;
    node* head = buildThreeNodeList(10, 20, 30);
    // list.setTop(head);

    // list.insertData(1, 15); // Insert at position 1
    // ASSERT_EQ(15, list.getTop()->next->data);
}

TEST_F(LinkedListTest, RemoveTest) {
    LinkedList list;
    node* head = buildThreeNodeList(100, 200, 300);
    // list.setTop(head);

    // list.remove(1); // Remove node at position 1
    // ASSERT_EQ(300, list.getTop()->next->data);
}

TEST_F(LinkedListTest, SizeTest) {
    LinkedList list;
    // EXPECT_EQ(0, list.size());

    node* head = buildThreeNodeList(5, 10, 15);
    // list.setTop(head);
    // EXPECT_EQ(3, list.size());
}

TEST_F(LinkedListTest, ContainsTest) {
    LinkedList list;
    node* head = buildThreeNodeList(7, 14, 21);
    // list.setTop(head);

    // EXPECT_TRUE(list.contains(14));
    // EXPECT_FALSE(list.contains(99));
}
