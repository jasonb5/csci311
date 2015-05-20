/**
 * @file hash_function.cpp    Hash function implementation.
 *
 * @brief
 *    Hash function implementation   
 *
 * @author Jason Boutte
 * @date 3/26/14
 */
 
#include <string>
#include "hash.h"
#include <cmath>

using namespace std;

/**
 * This hash function works by rotating the 8 bit value by
 * 4 bits and adding it to a sum. Then we XOR the sum by 
 * the original value. This works becuase its randomizes 
 * the bits pretty well. We rotate the least significant
 * bits (lsb) and the most significant bits (msb) moving
 * the more dynamic bits and creating a good differentiation
 * of values. I came upon this idea when reading about using
 * primes to create unique values.
 *
 * https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function
 * https://en.wikipedia.org/wiki/Jenkins_hash_function
 */
int Hash::hf(string ins) {
   int hash(0);

   for (unsigned int i = 0; i < ins.size(); ++i) {
      hash += (ins[i] >> 4) | ((ins[i] & 0x0f) << 4);
  
      hash ^= ins[i];
   }

   return hash % HASH_TABLE_SIZE;
}
