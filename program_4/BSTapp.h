/**
 * @file BSTapp.h Declaration of tree program
 *
 * @brief
 *    This program will prompt for input to add nodes
 *    to a binary search tree and perform functions
 *    on the tree.
 *
 * @author Jason Boutte
 * @date 4/16/14
 */

#ifndef _PROGRAM4_BSTAPP_H
#define _PROGRAM4_BSTAPP_H

#include "BST.h"

class BSTapp {
 public:
   BSTapp();                     // constructor
   ~BSTapp();                    // deconstructor

   void run();                   // main execution loop
   bool promptCommand();         // prompts for a commnad
   bool processCommand(string);  // process given command

 private:
   BST *tree;                    // holds binary search tree
};

#endif // _PROGRAM4_BSTAPP_H
