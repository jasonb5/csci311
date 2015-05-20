/**
 * @file MSTapp.cpp  Implementation of MSTapp class.
 *
 * @brief
 *    Main application class. Creates graph instance and
 *    parses input data from stdin. Populates graph
 *    with vertices and edges.
 *
 * @author Jason Boutte
 * @date 5/5/14
 */

#include "MSTapp.h"

#include <iostream>

using std::cin;

/**
 * MSTapp constructor
 */
MSTapp::MSTapp()
   :  root(NULL),
      graph(NULL) {

}

/**
 * MSTapp deconstructor
 */
MSTapp::~MSTapp() {
   delete root;

   delete graph;
}

/**
 * Main loop
 *
 * Main program loop. Gets data from stdin and 
 * passes to corresponding function. First line
 * is assumed to be vertices and every line after
 * are edges.
 */
void MSTapp::run() {
   bool first(true);

   graph = new Graph();

   while (true) {
      string line;

      getline(cin, line);

      if (line.size() == 0) {
         break;
      }

      if (first) {
         parseVertices(line);

         first = false;
      } else {
         parseEdges(line);
      }
   }

   graph->mstPrim(*root);
}

/**
 * Parse vertices
 *
 * Parses vertices from string. Each vertice must
 * be followed by a space.
 *
 * @param s String containing space separated vertices.
 */
void MSTapp::parseVertices(string s) {
   bool first(true);
   unsigned int last(-2);
   unsigned int index(-1);
   
   while (true) {
      index = s.find(' ', index + 2) - 1;

      if (index > s.size()) {
         /**
          * Possible case where the last letter
          * is not followed by a space.
          */
         string lv = s.substr(last + 2, s.size() - last - 1);

         if (lv.size() > 0) {
            graph->addVertex(lv);
         }

         break;
      }

      if (first) {
         root = new string(s.substr(index, index - last - 1));

         first = false;
      }

      graph->addVertex(s.substr(index, index - last - 1));

      last = index;
   }
}

/**
 * Parse edges
 *
 * Parses edges from string. Each edge is added
 * twice since it's undirected.
 *
 * @param s String containing edges
 */
void MSTapp::parseEdges(string s) {
   int last(0);
   int index(0);
   int weight(0);

   index = s.find(' ', 0);

   string a = s.substr(0, index);

   last = index + 1;

   index = s.find(' ', last);

   string b = s.substr(index - 1, index - last);

   last = index + 1;

   weight = stoi(s.substr(index + 1, index - s.size()));

   graph->addEdge(a, b, weight);

   graph->addEdge(b, a, weight);
}

/**
 * Entry point
 */
int main() {
   MSTapp app;

   app.run();

   return 0;
}
