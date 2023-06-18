/**
 * This is mostly the same graph we briefly worked with in tute 7,
 * but I've modified it to make it directed this time and changed
 * some of the interface to remove stuff we won't need and add some
 * stuff that we will need.
 */


#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>


typedef int Vertex;
typedef struct graph *Graph;


/** Build a graph with a fixed number of vertices. */
Graph buildGraph(int);

/** Insert an edge between two vertices into a graph. */
void  insertEdge(Graph, Vertex, Vertex);

/** Return the number of vertices in the graph. */
int   numVertices(Graph);

/** Check whether two vertices are connected in a graph. */
bool  connected(Graph, Vertex, Vertex);

/** Free all memory associated with a graph. */
void  freeGraph(Graph);


#endif // GRAPH_H
