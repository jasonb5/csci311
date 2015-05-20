#include "BST.h"
#include "include/gtest/gtest.h"

class BSTTest : public ::testing::Test {
public:   
   BST tree;
   
   BSTTest() {

   }

   virtual void SetUp() {
      tree.insertKey("8", "Data 8");
      tree.insertKey("1", "Data 1");
      tree.insertKey("7", "Data 7");
      tree.insertKey("6", "Data 6");
      tree.insertKey("2", "Data 2");
      tree.insertKey("3", "Data 3");
      tree.insertKey("5", "Data 5");
      tree.insertKey("9", "Data 9");
   }

   virtual void TearDown() {

   }
};

TEST_F(BSTTest, Insert) {
   tree.insertKey("4", "Data 4");

   tree.print();
}

TEST_F(BSTTest, FindExist) {
   Node *node = tree.findKey("5");

   ASSERT_NE(node, NULL);
}

int main(int argc, char **argv) {
   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}
