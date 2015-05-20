/**
 * @file Node.cpp Implementation of a tree Node
 *
 * @brief
 *    Implementation of a tree node. Key and data are stored.
 *    Reference to parent and children nodes.
 *
 * @author Jason Boutte
 * @date 4/16/14
 */

#include "Node.h"

/**
 * Constructor
 *
 * Initialize node data, making copies of key and data.
 *
 * @param key Node identifier
 * @param data Node data
 */
Node::Node(string &key, string &data) 
   :  key(new string(key)),
      data(new string(data)),
      parent(NULL),
      left(NULL),
      right(NULL) {

}

/**
 * Desconstructor
 *
 * Cleans up resources
 */
Node::~Node() {
   delete key;

   delete data;
}
