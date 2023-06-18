#include <stdio.h>

#include "Graph.h"


typedef struct edge {
    Vertex start;
    Vertex end;
} Edge;


/** Generate graphs from Q9. */
static Graph generateGraph1(void);
static Graph generateGraph2(void);
static Graph generateGraph3(void);
static Graph generateGraph4(void);

/** Prints a path on one line. */
static void  printPath(Edge *, int);


/**
 * Given a graph and a list of nE edges representing a path, determines whether
 * it is an Euler path.
 */
bool isEulerPath(Graph g, Edge *e, int nE) {
    // TODO: Complete this function
    return true;
}


int main(void) {
    // The path 0 -> 1 -> 2, which is an Euler path in graph 1
    Edge path1[] = {
        { .start = 0, .end = 1 },
        { .start = 1, .end = 2 }
    };

    // The same path, which is not an Euler path in graph 2 since
    // it only contains 2 of its 3 edges
    Edge *path2 = path1;

    // The path 0 -> 2 -> 3 -> 2 -> 1, which is not an Euler path in graph 3
    // This graph cannot have an Euler path, since all of its vertices have odd degree
    Edge path3[] = {
        { .start = 0, .end = 2 },
        { .start = 2, .end = 3 },
        { .start = 3, .end = 2 },
        { .start = 2, .end = 1}
    };

    // The path 0 -> 1 -> 2 -> 0 -> 3 -> 1, which is not an Euler path in graph 4
    // Similarly to graph 3, it cannot have an Euler path
    Edge path4[] = {
        { .start = 0, .end = 1 },
        { .start = 1, .end = 2 },
        { .start = 2, .end = 0 },
        { .start = 0, .end = 3 },
        { .start = 3, .end = 1 }
    };

    Graph g1 = generateGraph1();
    Graph g2 = generateGraph2();
    Graph g3 = generateGraph3();
    Graph g4 = generateGraph4();

    printPath(path1, 2);
    printf(
        "Is this an Euler path in graph 1? %s\n\n",
        isEulerPath(g1, path1, 2) ? "yes" : "no"
    );

    printPath(path2, 2);
    printf(
        "Is this an Euler path in graph 2? %s\n\n",
        isEulerPath(g2, path2, 2) ? "yes" : "no"
    );

    printPath(path3, 4);
    printf(
        "Is this an Euler path in graph 3? %s\n\n",
        isEulerPath(g3, path3, 4) ? "yes" : "no"
    );

    printPath(path4, 5);
    printf(
        "Is this an Euler path in graph 4? %s\n",
        isEulerPath(g4, path4, 5) ? "yes" : "no"
    );

    return 0;
}


static Graph generateGraph1(void) {
    Graph g = buildGraph(3);
    insertEdge(g, 0, 1);
    insertEdge(g, 1, 2);
    return g;
}

static Graph generateGraph2(void) {
    Graph g = generateGraph1();
    insertEdge(g, 2, 0);
    return g;
}

static Graph generateGraph3(void) {
    Graph g = buildGraph(4);
    insertEdge(g, 0, 2);
    insertEdge(g, 1, 2);
    insertEdge(g, 2, 3);
    return g;
}

static Graph generateGraph4(void) {
    Graph g = generateGraph3();
    insertEdge(g, 0, 1);
    insertEdge(g, 0, 3);
    insertEdge(g, 1, 3);
    return g;
}

static void printPath(Edge *e, int nE) {
    printf("%d", e[0].start);
    for (int i = 0; i < nE; i++) {
        printf(" -> %d", e[i].end);
    }
    printf("\n");
}
