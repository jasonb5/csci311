/**
 * @file BSTapp.cpp Implmentation of binary search tree program
 *
 * @brief
 *    This program will prompt for input to add nodes
 *    to a binary search tree and permform functions
 *    on the tree.
 *
 * @author Jason Boutte
 * @date 4/16/14
 */

#include "BSTapp.h"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/**
 * Constructor
 *
 * Initializes values
 */
BSTapp::BSTapp() 
   : tree(new BST()) {
   
}

/**
 * Deconstructor
 *
 * Cleans up on delete
 */
BSTapp::~BSTapp() {

}

/**
 * Main execution loop
 *
 * Continues to prompt user until promptCommand
 * returns false
 */
void BSTapp::run() {
   while (true) {
      if (!promptCommand()) {
         break;
      }
   }
}

/**
 * Prompts user for a command
 *
 * Prompts user for a command then processes command.
 * 
 * @return true if command was successful
 */
bool BSTapp::promptCommand() {
   string s;

   getline(cin, s);

   return processCommand(s);
}

/**
 * Process given commands
 *
 * Processes given commands by parsing out the command,
 * key and data associated with the key.
 *
 * @param true if command was successful
 */
bool BSTapp::processCommand(string s) {
   int fIndex = s.find(' ');
   int sIndex = s.find(' ', fIndex + 1);

   string command = s.substr(0, fIndex);
   string key = s.substr(fIndex + 1, sIndex - fIndex - 1);
   string data = s.substr(sIndex + 1);

   if (command == "quit") {
      return false;
   } else if (command == "print") {
      tree->print();
   } else {
      // check to make sure key was given
      if (command != key && key.size() > 0) {
         if (command == "insert") {
            tree->treeInsert(key, data);
         } else if (command == "find") {
            tree->treeSearch(key);
         } else if (command == "delete") {
            tree->treeDelete(key, data);
         } else {
            cout << "Unknown command \"" << command << "\"" << endl;
         }
      }
   }
   
   return true;
}

int main() {
   BSTapp app;

   app.run();

   return 0;  
}
