#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#include "Graph.h"


#define GRAPH_ERR   "Could not allocate memory for graph container"
#define MATRIX_ERR  "Could not allocate memory for adjacency matrix"


struct graph {
    bool **adjMatrix;
    int    nV;
};


static void *mallocSafely(size_t, const char *);
static bool  isVertex(Graph, Vertex);


Graph buildGraph(int dim) {
    Graph g = mallocSafely(sizeof(*g), GRAPH_ERR);

    g->adjMatrix = mallocSafely(dim * sizeof(bool *), MATRIX_ERR);
    for (Vertex i = 0; i < dim; i++) {
        g->adjMatrix[i] = mallocSafely(dim * sizeof(bool), MATRIX_ERR);
        memset(g->adjMatrix[i], false, dim * sizeof(bool));
    }

    g->nV = dim;

    return g;
}

void insertEdge(Graph g, Vertex u, Vertex v) {
    g->adjMatrix[u][v] = true;
}

int numVertices(Graph g) {
    return g->nV;
}

bool connected(Graph g, Vertex u, Vertex v) {
    return isVertex(g, u) && isVertex(g, v) && g->adjMatrix[u][v];
}

void freeGraph(Graph g) {
    free(g->adjMatrix);
    free(g);
}


static void *mallocSafely(size_t bytes, const char *warning) {
    void *mem = malloc(bytes);
    if (mem == NULL) {
        fprintf(stderr, "%s\n", warning);
        exit(EXIT_FAILURE);
    }

    return mem;
}

static bool isVertex(Graph g, Vertex v) {
    return 0 <= v && v < g->nV;
}
