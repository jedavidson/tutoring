#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#include "Graph.h"


struct graph {
    bool **adj;
    int    nV;
    int    nE;
};

Graph build_graph(int dim) {
    Graph g = malloc(sizeof(*g));
    g->adj = malloc(dim * sizeof(bool *));
    for (Vertex i = 0; i < dim; i++) {
        g->adj[i] = malloc(dim * sizeof(bool));
        memset(g->adj[i], false, dim * sizeof(bool));
    }

    g->nV = dim;
    g->nE = 0;
    return g;
}

void insert(Graph g, Vertex u, Vertex v) {
    g->adj[u][v] = g->adj[v][u] = true;
    g->nE++;
}

int num_edges(Graph g) {
    return g->nE;
}

bool is_vertex(Graph g, Vertex v) {
    return 0 <= v && v < g->nV;
}

bool connected(Graph g, Vertex u, Vertex v) {
    return is_vertex(g, u) && is_vertex(g, v) && g->adj[u][v];
}

void free_graph(Graph g) {
    free(g->adj);
    free(g);
}
