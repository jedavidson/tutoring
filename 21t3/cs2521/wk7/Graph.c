#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "Graph.h"


#define GRAPH_ERR   "Could not allocate memory for graph container"
#define MATRIX_ERR  "Could not allocate memory for adjacency matrix"


struct graph {
    bool **adjMatrix;
    int    nV;
    int    nE;
};


static void *mallocSafely(size_t, char *);


Graph buildGraph(int dim) {
    Graph g = mallocSafely(sizeof(*g), GRAPH_ERR);

    g->adjMatrix = mallocSafely(dim * sizeof(bool *), MATRIX_ERR);
    for (Vertex i = 0; i < dim; i++) {
        g->adjMatrix[i] = mallocSafely(dim * sizeof(bool), MATRIX_ERR);
        for (Vertex j = 0; j < dim; j++) {
            g->adjMatrix[i][j] = false;
        }
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
    return isVertex(g, u)
        && isVertex(g, v)
        && g->adjMatrix[u][v]
        && g->adjMatrix[v][u];
}

void freeGraph(Graph g) {
    free(g->adjMatrix);
    free(g);
}


static void *mallocSafely(size_t bytes, char *warning) {
    void *mem = malloc(bytes);
    if (mem == NULL) {
        fprintf(stderr, "%s\n", warning);
        exit(EXIT_FAILURE);
    }

    return mem;
}
