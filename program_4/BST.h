/**
 * @file BST.h Declaration of Binary Search Tree
 *
 * @brief
 *    Implmentation of a Binary Search Tree. Nodes are stored and 
 *    sorted into a tree structure.
 *
 * @author Jason Boutte
 * @date 4/16/14
 */

#ifndef _PROGRAM4_BST_H
#define _PROGRAM4_BST_H

#include "Node.h"

class BST {
 public:
   BST();                              // constructor 
   ~BST();                             // deconstructor

   void treeInsert(string&, string&);  // inserts key and data
   void treeSearch(string);            // searchs for key
   void treeDelete(string, string);    // deletes key and data
   void print();                       // prints tree

 private:
   Node *root;                         // trees root node

   void inorderTreeWalk(Node*, int);   // walks tree left then right
   Node *treeSearch(Node*, string);    // searchs tree starting at node
   void treeDelete(Node*);             // deletes node
   void transplant(Node*, Node*);      // transplants nodes
   Node *treeMinimum(Node*);           // finds tree minimum
};

#endif // _PROGRAM4_BST_H
