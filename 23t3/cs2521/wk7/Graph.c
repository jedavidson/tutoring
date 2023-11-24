#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "Graph.h"

struct graph {
    bool **adj;
    int vertices;
    int edges;
};

Graph graph_new(int n) {
    Graph g = malloc(sizeof(*g));
    g->adj = malloc(n * sizeof(bool *));
    for (Vertex v = 0; v < n; v++) {
        g->adj[v] = malloc(n * sizeof(bool));
        memset(g->adj[v], false, n * sizeof(bool));
    }

    g->vertices = n;
    g->edges = 0;
    return g;
}

void graph_free(Graph g) {
    for (Vertex v = 0; v < g->vertices; v++) {
        free(g->adj[v]);
    }
    free(g->adj);
    free(g);
}

void graph_insert_edge(Graph g, Vertex u, Vertex v) {
    g->adj[u][v] = g->adj[v][u] = true;
    g->edges++;
}

bool graph_adjacent(Graph g, Vertex u, Vertex v) {
    bool v_exists = 0 <= v && v < g->vertices;
    bool w_exists = 0 <= v && v < g->vertices;
    return v_exists && w_exists && g->adj[u][v];
}

int graph_num_vertices(Graph g) {
    return g->vertices;
}

int graph_num_edges(Graph g) {
    return g->edges;
}
