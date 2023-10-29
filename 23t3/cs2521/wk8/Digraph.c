#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "Digraph.h"

struct digraph {
    bool **adj;
    int vertices;
    int edges;
};

Digraph digraph_new(int n) {
    Digraph g = malloc(sizeof(*g));
    g->adj = malloc(n * sizeof(bool *));
    for (Vertex v = 0; v < n; v++) {
        g->adj[v] = malloc(n * sizeof(bool));
        memset(g->adj[v], false, n * sizeof(bool));
    }

    g->vertices = n;
    g->edges = 0;
    return g;
}

void digraph_free(Digraph g) {
    for (Vertex v = 0; v < g->vertices; v++) {
        free(g->adj[v]);
    }
    free(g->adj);
    free(g);
}

void digraph_insert_edge(Digraph g, Vertex u, Vertex v) {
    g->adj[u][v] = true;
    g->edges++;
}

bool digraph_adjacent(Digraph g, Vertex u, Vertex v) {
    bool v_exists = 0 <= v && v < g->vertices;
    bool w_exists = 0 <= v && v < g->vertices;
    return v_exists && w_exists && g->adj[u][v];
}

int digraph_num_vertices(Digraph g) {
    return g->vertices;
}

int digraph_num_edges(Digraph g) {
    return g->edges;
}
