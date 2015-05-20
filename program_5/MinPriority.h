/**
 * @file MinPriority.h  Declaration of the MinPriority class.
 *
 * @author Jason Boutte
 * @date 5/5/14
 */

#ifndef _PROGRAM5_MINPRIORITY_H
#define _PROGRAM5_MINPRIORITY_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class MinPriority {
 public:
   MinPriority();                // constructor
   ~MinPriority();               // deconstructor
    
   void addElement(string, int); // add element
   void buildMinHeap();          // build min heap
   string *extractMin();         // extract min
   int getHeapSize();            // get heap size
   bool hasElement(string*);     // contains element
   void updateKey(string*, int); // update element key
   void minHeapify(int);         // perform min heapify

 private:
   class Element {               // Inner element class
    public:
      Element(string, int);      // Element constructor
      ~Element();                // Element deconstructor
      
      string *id;                // Element identifier
      int key;                   // Element key
   };

   int parent(int);              // get parent index
   int left(int);                // get left index
   int right(int);               // get right index

   int heapSize;                 // current heap size
   vector<Element*> minHeap;     // min heap vector
};

#endif

