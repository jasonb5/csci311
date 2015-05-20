#include "Graph.h"
#include "MinPriority.h"

#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Graph constructor.
 */
Graph::Graph()
   :  vertexList() {

}

/**
 * Graph deconstructor.
 */
Graph::~Graph() {
   for (unsigned int i = 0; i < vertexList.size(); ++i) {
      Vertex *v = vertexList[i];

      delete v;
   }
}

/**
 * Add vertex
 *
 * Add a vertex with a new identifier.
 *
 * @param i Vertex identifier.
 */
void Graph::addVertex(string i) {
   vertexList.push_back(new Vertex(i));
}

/**
 * Add edge
 *
 * Add an edge from i to j identifiers with weight
 * k to adjacency list.
 *
 * @param i Starting identifier.
 * @param j Destination identifer.
 * @param k Edge weight.
 */
void Graph::addEdge(string i, string j, int k) {
   Vertex *v = getVertex(&i);

   v->adjacent.push_back(new Vertex(j, k));

   sort(v->adjacent.begin(), v->adjacent.end());
}

/**
 * Prim's algorithm
 *
 * Starts Prim's algorithm starting with s
 * as the root of the MST.
 *
 * @param s Root of MST.
 */
void Graph::mstPrim(string s) {
   int weight(0);
   MinPriority queue;
   vector<Vertex*>::iterator it;

   // setup min priority queue with default key values
   for (it = vertexList.begin(); it != vertexList.end(); ++it) {
      if (*(*it)->id == s) {
         (*it)->key = 0;
         
         queue.addElement(*(*it)->id, 0);
      } else {
         queue.addElement(*(*it)->id, 101);
      }
   }  

   queue.buildMinHeap();

   while (queue.getHeapSize() > 0) {
      string *u = queue.extractMin();
   
      Vertex *adjU = getVertex(u); // get adjacency list for vertex
   
      /**
       * Iterate through adjacency list and update values.
       * The objects in the adjacency list are placeholders,
       * real vertex object is retrieved and its values are
       * updated.
       */
      for (it = adjU->adjacent.begin(); it != adjU->adjacent.end(); ++it) {
         Vertex *n = getVertex((*it)->id);
         
         if (queue.hasElement((*it)->id) && (*it)->weight < n->key) {
            n->pred = adjU;

            n->key = (*it)->weight;

            queue.updateKey(n->id, n->key);
         }
      }

      queue.minHeapify(0); // rebuilds heap

      weight += adjU->key;

      printEdge(adjU);
   }

   cout << weight << endl;
}

/**
 * Prints edge
 *
 * Prints edge information.
 *
 * @param v Edge to print.
 */
void Graph::printEdge(Vertex *v) {
   cout << *v->id << " ";

   if (v->pred == NULL) {
      cout << "NIL";
   } else {
      cout << *v->pred->id;
   }

   cout << " " << v->key << endl;
}

/**
 * Finds vertex
 *
 * Searches vertexList for vertex with the
 * matching identifier.
 *
 * @param u Vertex identifier.
 * 
 * @return Matching vertex or NULL.
 */
Graph::Vertex *Graph::getVertex(string *u) {
   vector<Vertex*>::iterator it;

   for (it = vertexList.begin(); it != vertexList.end(); ++it) {
      if (*(*it)->id == *u) {
         return *it;
      }
   }

   return NULL;
}

/**
 * Vertex constructor.
 * 
 * @param i Vertex identifier.
 */
Graph::Vertex::Vertex(string i)
   :  pred(NULL),
      id(NULL),
      key(101),
      weight(0),
      adjacent() {
   id = new string(i);
}

/**
 * Vertex Edge constructor.
 *
 * @param i Edge destination identifier.
 * @param k Edge weight.
 */
Graph::Vertex::Vertex(string i, int k)
   :  pred(NULL),
      id(NULL),
      key(101),
      weight(k), 
      adjacent() {   
   id = new string(i);
}

/**
 * Vertex deconstructor.
 */
Graph::Vertex::~Vertex() {
   delete id;
}
