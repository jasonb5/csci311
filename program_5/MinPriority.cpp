/**
 * @file MinPriority.cpp   Implementation of Min Priority queue.
 *
 * @brief 
 *    Implementation of a minimum priority queue.
 *
 * @author Jason Boutte
 * @date 5/5/14
 */

#include "MinPriority.h"

/**
 * MinPriority constructor.
 */
MinPriority::MinPriority()
   :  heapSize(0),
      minHeap() {

}

/**
 * MinPriority deconstructor.
 */
MinPriority::~MinPriority() {
   for (unsigned int i = 0; i < minHeap.size(); ++i) {
      Element *e = minHeap[i];

      delete e;
   }
}

/**
 * Add element to queue
 *
 * Adds a new element with key to queue.
 *
 * @param i Element identifier.
 * @param k Element key.
 */
void MinPriority::addElement(string i, int k) {
   minHeap.push_back(new Element(i, k));
}

/**
 * Build Min Heap
 *
 * Build the minimum heap.
 */
void MinPriority::buildMinHeap() {
   heapSize = minHeap.size();;

   for (int i = (minHeap.size() - 1)/ 2; i >= 1; --i) {
      minHeapify(i - 1);
   }
}

/**
 * Extract minimum element identifer
 *
 * Adjusts the minHeap and decrements
 * heap size and returns minimum id.
 *
 * @return Minimum identifier.
 */
string *MinPriority::extractMin() {
   Element *e = minHeap[0];

   minHeap[0] = minHeap[heapSize - 1];
   
   minHeap[heapSize - 1] = e;

   --heapSize;

   return e->id;
}

/**
 * Heap size
 *
 * @return Current heap size.
 */
int MinPriority::getHeapSize() {
   return heapSize;
}

/**
 * Check for element
 *
 * Checks to see if an element with the
 * identifier is still part of the heap.
 *
 * @param s Element identifier
 * 
 * @return True if element is in heap, or false
 */
bool MinPriority::hasElement(string *s) {
   for (int i = 0; i < heapSize; ++i) {
      if (*minHeap[i]->id == *s) {
         return true;
      }
   }

   return false;
}

/**
 * Update element key
 *
 * Updates element key with new value.
 *
 * @param s Element identifier.
 * @param k New key for element.
 */
void MinPriority::updateKey(string *s, int k) {
   for (unsigned int i = 0; i < minHeap.size(); ++i) {
      if (*minHeap[i]->id == *s) {
         minHeap[i]->key = k;
         
         break;
      }
   }
}

/**
 * Min heapify
 *
 * Re-organizes min heap based on current
 * element keys.
 *
 * @param i Element index to start at.
 */
void MinPriority::minHeapify(int i) {
   int l = left(i + 1) - 1;
   int r = right(i + 1) - 1;
   int smallest(i);

   if (l < heapSize && minHeap[l]->key < minHeap[i]->key) {
      smallest = l;
   }

   if (r < heapSize && minHeap[r]->key < minHeap[smallest]->key) {
      smallest = r;
   }

   if (smallest != i) {
      Element *e = minHeap[i];

      minHeap[i] = minHeap[smallest];

      minHeap[smallest] = e;

      minHeapify(smallest);
   }
}

/**
 * Returns parent index.
 */
int MinPriority::parent(int i) {
   return i/2;
}

/**
 * Returns left element.
 */
int MinPriority::left(int i) {
   return i * 2;
}

/**
 * Returns right element.
 */
int MinPriority::right(int i) {
   return (i * 2) + 1;
}

/**
 * Element constructor.
 */
MinPriority::Element::Element(string i, int k) 
   :  id(NULL),
      key(k) {
   id = new string(i);
}

/**
 * Element deconstructor.
 */
MinPriority::Element::~Element() {
   delete id;
}
