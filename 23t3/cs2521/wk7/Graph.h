#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

/** A vertex in the graph will just be represented by a number. */
typedef int Vertex;

/** A graph. */
typedef struct graph *Graph;

/** Creates an empty graph for a fixed number of vertices. */
Graph graph_new(int n);

/** Frees all memory associated with a graph. */
void graph_free(Graph g);

/** Inserts an edge between two vertices into a graph. */
void graph_insert_edge(Graph g, Vertex v, Vertex w);

/** Checks whether two vertices are adjacent/connected in a graph. */
bool graph_adjacent(Graph g, Vertex v, Vertex w);

/** Returns the number of vertices in the graph. */
int graph_num_vertices(Graph g);

/** Returns the number of edges in the graph. */
int graph_num_edges(Graph g);

#endif // GRAPH_H
