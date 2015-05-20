/**
 * @file Hash.cpp Tools for manipulating hashtable.
 * 
 * @brief
 *    Process file and stores values in a hashtable.
 *    We can search, remove, output or print the 
 *    values of the hashtable. We can also print
 *    stats related to the hashtable.
 *
 * @author Jason Boutte
 * @date 3/26/14
 */

#include "hash.h"

#include <fstream>
#include <iostream>
#include <algorithm>

/**
 * Removes value from hashtable
 *
 * Searches hashtable for the value. We remove
 * the value using the hashed key. We update the
 * avgLength variable on a successful remove.
 *
 * @param s Value to remove from the hashtable
 */
void Hash::remove(string s) {
   int hash(0);
   list<string>::iterator it;

   it = find(s, &hash);

   if (it != hashTable[hash].end()) {
      hashTable[hash].erase(it);
      
      updateAvgLength();
   }
}

/**
 * Prints the hashtable
 *
 * Prints the hashtable to the constole.
 */
void Hash::print() {
   int i(0);
   list<string>::iterator it;

   for (i = 0; i < HASH_TABLE_SIZE; ++i) {
      cout << i << ":\t";

      for (it = hashTable[i].begin(); it != hashTable[i].end(); ++it) {
         cout << *it << ", ";
      }

      cout << endl;
   }
}

/**
 * Processes an input file
 *
 * Opens file containing values and 
 * inserts them into the hashtable
 *
 * @param s Filename containing the new values.
 */
void Hash::processFile(string s) {
   ifstream ifs;

   // initialize variables
   collisions = 0;
   longestList = 0;
   avgLength = 0.0;

   ifs.open(s);

   while (!ifs.eof()) {
      string tmp;

      getline(ifs, tmp);
  
      if (tmp.empty()) continue; // check for empty line

      insert(tmp); // insert value into hashtable
   }

   ifs.close();
}

/**
 * Searches hashtable
 *
 * Searches the hashtable for a value.
 *
 * @param s Value to search for
 *
 * @return True if found, otherwise false
 */
bool Hash::search(string s) {
   int hash(0);
   list<string>::iterator it;
   
   it = find(s, &hash);

   return (it == hashTable[hash].end()) ? false : true;
}

/**
 * Prints hashtable to output file
 *
 * Prints a formatted hashtable to a file.
 *
 * @param s File to print hashtable to
 */
void Hash::output(string s) {
   int i(0);
   ofstream ofs;
   list<string>::iterator it;

   ofs.open(s);

   for (i = 0; i < HASH_TABLE_SIZE; ++i) {
      ofs << i << ":\t";

      for (it = hashTable[i].begin(); it != hashTable[i].end(); ++it) {
         ofs << *it << ", ";
      }

      ofs << endl;
   }

   ofs.close();
}

/**
 * Prints hashtable stats
 */
void Hash::printStats() {
   cout << "Total collisions = " << collisions << endl;

   cout << "Longest list = " << longestList << endl;

   cout << "Average list length = " << avgLength << endl;
}

/**
 * Helper function 
 *
 * Helper function that generates key and
 * searches the hashtable for the value
 *
 * @param s    Value to search for
 * @param hash Point that holds generated key
 *
 * @return Returns iterator
 */
list<string>::iterator Hash::find(string s, int* hash) {
   *hash = hf(s);

   return std::find(hashTable[(*hash)].begin(), hashTable[(*hash)].end(), s);
}

/**
 * Insets value into hashtable
 *
 * Generates key from value and inserts into
 * hashtable. Update collisions, longestList
 * and avnLength.
 *
 * @param s Value to insert
 */
void Hash::insert(string s) {
   int hash(0);
   unsigned int i(0);

   hash = hf(s);

   if (hashTable[hash].size() > (unsigned int)0) {
      ++collisions;
   }

   hashTable[hash].push_back(s);

   for (i = 0; i < HASH_TABLE_SIZE; ++i) {
      if ((unsigned int)longestList < hashTable[i].size()) {
         longestList = hashTable[i].size();
      }
   }

   updateAvgLength();
}

/**
 * Updates avgLength stat
 *
 * Updates avgLength by taking the current average
 * and averaging it into our old value.
 */
void Hash::updateAvgLength() {
   int i(0);
   int lengthSum(0);
   double newAvgLen(0.0);

   for (i = 0; i < HASH_TABLE_SIZE; ++i) {
      lengthSum += hashTable[i].size();
   }

   newAvgLen = (double)lengthSum/(double)HASH_TABLE_SIZE;
   
   avgLength = (newAvgLen + avgLength)/2.0;
}
 
