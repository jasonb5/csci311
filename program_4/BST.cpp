/**
 * @file BST.cpp  Implementation of Binary Search Tree
 *
 * @brief
 *    Implementation of a Binary Search Tree. Nodes are stored and
 *    sorted into a tree structure.
 *
 *    Tree Property: Let n be a new node and x an existing. If 
 *    n.key < x.key then n is a left child otherwise a right child.
 *
 * @author Jason Boutte
 * @date 4/16/14
 */

#include "BST.h"

#include <iostream>

using std::cout;
using std::endl;

/**
 * Constructor
 *
 * Initializes tree values
 */
BST::BST() 
   : root(NULL) {

}
/**
 * Desconstructor
 *
 * Cleans up tree
 */
BST::~BST() {
   delete root;
}

/**
 * Inserts key and data
 *
 * We run through the tree following the tree property until
 * we find a leaf. The we attach the new node using the tree
 * property.
 * 
 * @param key Node key
 * @param data Node Data
 */
void BST::treeInsert(string& key, string& data) {
   Node *y(NULL);
   Node *x(root);
   Node *n = new Node(key, data);

   while (x != NULL) {
      y = x;
  
      if (*(n->key) < *(x->key)) {
         x = x->left;
      } else {
         x = x->right;
      }
   }

   n->parent = y;

   if (y == NULL) {
      root = n;
   } else if (*(n->key) < *(y->key)) {
      y->left = n;
   } else {
      y->right = n;
   } 
}

/** 
 * Searches for key
 *
 * We search for a node containing the key. If we find one
 * we print it out and start searching through the right 
 * of the found node for the next match.
 *
 * @param key Key we're searching for
 */
void BST::treeSearch(string key) {
   Node *node = treeSearch(root, key);

   while (node != NULL) {
      cout << *(node->key) << " " << *(node->data) << endl;

      node = treeSearch(node->right, key);
   } 
}

/**
 * Deletes key and data
 *
 * Search for a node containing the key and data. If found
 * it's removed from the tree.
 *
 * @param key Node search key
 * @param data Node search data
 */
void BST::treeDelete(string key, string data) {
   Node *node = treeSearch(root, key);

   while (node != NULL) {
      if (*(node->data) == data) {
         treeDelete(node);      
      }

      node = treeSearch(node->right, key);
   }
}

/** 
 * Prints the contents of the tree
 *
 * An Inorder tree walk is call starting at the root of the 
 * tree
 */
void BST::print() {
   inorderTreeWalk(root, 0);
}

/**
 * Walks the tree
 *
 * Prints the tree out in order.
 *
 * @param node Starting node
 * @param depth current depth of the tree
 */
void BST::inorderTreeWalk(Node* node, int depth) {
   if (node != NULL) {
      inorderTreeWalk(node->left, depth + 1);

      cout << depth << " " << *(node->key) << " " << *(node->data) << endl;

      inorderTreeWalk(node->right, depth + 1);
   }
}

/**
 * Searches the tree for a node
 *
 * Searches the tree starting at a node, looking for a node
 * containing the key.
 *
 * @param node Starting node
 * @param key Key being searched for
 * @return Node if found otherwise NULL
 */
Node* BST::treeSearch(Node* node, string key) {
   if (node == NULL || key == *(node->key)) {
      return node;
   }

   if (key < *(node->key)) {
      return treeSearch(node->left, key);
   } else {
      return treeSearch(node->right, key);
   }
}

/**
 * Deletes node from the tree
 *
 * Re-adjusts the tree based on where the node is located,
 * then deletes it.
 * 
 * @param z Node being deleted
 */
void BST::treeDelete(Node* z) {
   if (z->left == NULL) {
      transplant(z, z->right);   
   } else if (z->right == NULL) {
      transplant(z, z->left);
   } else {
      Node *y = treeMinimum(z->right);
      
      if (y->parent != z) {
         transplant(y, y->right);

         y->right = z->right;

         y->right->parent = y;
      }

      transplant(z, y);

      y->left = z->left;

      y->left->parent = y;
   }
}

/**
 * Transplants two Nodes
 *
 * Transplants two Nodes to maintain the tree property.
 *
 * @param u First node
 * @param v Second node
 */
void BST::transplant(Node* u, Node* v) {
   if (u->parent == NULL) {
      root = v;
   } else if (u == u->parent->left) {
      u->parent->left = v;
   } else {
      u->parent->right = v;
   }

   if (v != NULL) {
      v->parent = u->parent;
   }
}

/** 
 * Find the minimum node
 *
 * Finds the minimum node starting from x
 *
 * @param x Starting node
 */
Node* BST::treeMinimum(Node* x) {
   while (x->left != NULL) {
      x = x->left;
   }

   return x;
}
