#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>


typedef int Vertex;
typedef struct graph *Graph;


/** Build a graph with a fixed number of vertices. */
Graph build_graph(int);

/** Insert an edge between two vertices into a graph. */
void  insert(Graph, Vertex, Vertex);

/** Return the number of edges in the graph. */
int   num_edges(Graph);

/** Check whether a vertex exits in the graph. */
bool  is_vertex(Graph, Vertex);

/** Check whether two vertices are connected in a graph. */
bool  connected(Graph, Vertex, Vertex);

/** Free all memory associated with a graph. */
void  free_graph(Graph);


#endif // GRAPH_H
