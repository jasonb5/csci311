/**
 * @file Hash.h   Declaration of the Hash class.
 *
 * @author Jason Boutte
 * @date 3/26/14
 */

#ifndef __HASH_H
#define __HASH_H

#include <string>
#include <list>

using namespace std;

class Hash {

public:
  void remove ( string );                       // removes value from table
  void print ( );                               // prints current table
  void processFile ( string );                  // processes file 
  bool search ( string );                       // searches table for value
  void output ( string );                       // prints table to file
  void printStats ( );                          // prints table stats

private:
   list<string> hashTable [HASH_TABLE_SIZE];    // hashtable
   int collisions;                              // insertion collisions
   int longestList;                             // biggest set of values
   double avgLength;                            // running average length
   
private:
   int hf ( string );                           // hashing function

// put additional variables/functions below
// do not change anything above!
   list<string>::iterator find(string, int*);   // helper search function
   void insert(string);                         // inserts value
   void updateAvgLength();                      // updates average length
};

#endif
