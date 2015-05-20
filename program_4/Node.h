/**
 * @file Node.h   Declaration of tree node
 *
 * @brief
 *    Implementation of a tree node. Key and data are stored.
 *    Reference to parent and children nodes.
 *
 * @author Jason Boutte
 * @date 4/16/14
 */

#ifndef _PROGRAM4_NODE_H
#define _PROGRAM4_NODE_H

#include <string>

using std::string;

class Node {
 friend class BST;         // easy access
 
 public:
   Node(string&, string&); // constructor
   ~Node();                // clean up resources

 private:
   string *key;            // node identifier
   string *data;           // node data
   Node *parent;           // node parent
   Node *left;             // left child node
   Node *right;            // right child node
};

#endif // _PROGRAM4_NODE_H
