/**
 * @file Graph.h  Declaration of the Graph class.
 *
 * @author Jason Boutte
 * @date 5/5/14
 */

#ifndef _PROGRAM5_GRAPH_H
#define _PROGRAM5_GRAPH_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class Graph {
 public:
   Graph();                            // constructor
   ~Graph();                           // deconstructor

   void addVertex(string);             // add vertex
   void addEdge(string, string, int);  // add edge
   void mstPrim(string);               // perform prim's

 private:
   class Vertex {                      // inner vertex class
    public:
      Vertex(string);                  // vertex constructor
      Vertex(string, int);             // vertex constructor
      ~Vertex();                       // vertex deconstructor

      inline bool operator < (const Vertex &i) { // operator override
         return (*id < *i.id);
      }

      Vertex* pred;                    // vertex parent
      string *id;                      // vertex id
      int key;                         // vertex key
      int weight;                      // edge weight
      vector<Vertex*> adjacent;        // adjaceny list
   };

   void printEdge(Vertex*);
   Vertex *getVertex(string*);

   vector<Vertex*> vertexList;
};

#endif // _PROGRAM5_GRAPH_H
