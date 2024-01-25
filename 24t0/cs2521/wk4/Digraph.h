#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

/** A vertex in the graph will just be represented by a number. */
typedef int Vertex;

/** A directed graph. */
typedef struct digraph *Digraph;

/** Creates an empty graph for a fixed number of vertices. */
Digraph digraph_new(int n);

/** Frees all memory associated with a graph. */
void digraph_free(Digraph g);

/** Inserts an edge between two vertices into a graph. */
void digraph_insert_edge(Digraph g, Vertex v, Vertex w);

/** Checks whether two vertices are adjacent/connected in a graph. */
bool digraph_adjacent(Digraph g, Vertex v, Vertex w);

/** Returns the number of vertices in the graph. */
int digraph_num_vertices(Digraph g);

/** Returns the number of edges in the graph. */
int digraph_num_edges(Digraph g);

#endif // GRAPH_H
