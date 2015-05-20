/**
 * @file MSTapp.h Declaration of MSTapp class.
 *
 * @author Jason Boutte
 * @date 5/5/14
 */

#ifndef _PROGRAM5_MSTAPP_H
#define _PROGRAM5_MSTAPP_H

#include "Graph.h"

class MSTapp {
 public:
   MSTapp();                  // constructor
   ~MSTapp();                 // deconstructor

   void run();                // main loop

 private:
   void parseVertices(string);// vertex helper
   void parseEdges(string);   // edge helper

   string *root;              // root vertex
   Graph *graph;              // MST graph
};

#endif // _PROGRAM5_MSTAPP_H
