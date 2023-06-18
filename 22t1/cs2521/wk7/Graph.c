#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#include "Graph.h"


struct graph {
    bool **adjMatrix;
    int    nV;
    int    nE;
};

Graph buildGraph(int dim) {
    Graph g = malloc(sizeof(*g));
    g->adjMatrix = malloc(dim * sizeof(bool *));
    for (Vertex i = 0; i < dim; i++) {
        g->adjMatrix[i] = malloc(dim * sizeof(bool));
        memset(g->adjMatrix[i], false, dim * sizeof(bool));
    }

    g->nV = dim;
    g->nE = 0;
    return g;
}

void insertEdge(Graph g, Vertex u, Vertex v) {
    g->adjMatrix[u][v] = g->adjMatrix[v][u] = true;
    g->nE++;
}

int numEdges(Graph g) {
    return g->nE;
}

bool isVertex(Graph g, Vertex v) {
    return 0 <= v && v < g->nV;
}

bool connected(Graph g, Vertex u, Vertex v) {
    return isVertex(g, u) && isVertex(g, v) && g->adjMatrix[u][v];
}

void freeGraph(Graph g) {
    free(g->adjMatrix);
    free(g);
}
