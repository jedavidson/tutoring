#include <stdio.h>

#include "Graph.h"


typedef struct edge {
    Vertex start;
    Vertex end;
} Edge;


/** Generate graph 1 from Q9. */
static Graph generateGraph1(void);

/** Generate graph 2 from Q9. */
static Graph generateGraph2(void);

/** Generate graph 3 from Q9. */
static Graph generateGraph3(void);

/** Generate graph 4 from Q9. */
static Graph generateGraph4(void);

/** Prints a path on one line. */
static void  printPath(Edge *, int);


bool isEulerPath(Graph g, Edge *e, int nE) {
    // An Euler path is a path in the graph which visits each edge
    // exactly once. Since we want to check if a given path is an
    // Euler path, let's break that definition down into the things
    // we should be checking:

    // (1) An Euler path must be a path, i.e. for each edge in the
    //     path, the end point must be the start point of the next.
    for (int i = 0; i < nE - 1; i++) {
        if (e[i].end != e[i + 1].start) {
            return false;
        }
    }

    // (2) An Euler path must be a valid path in the graph,
    //     i.e. it must contain edges actually in the graph.
    for (int i = 0; i < nE; i++) {
        if (!connected(g, e[i].start, e[i].end)) {
            return false;
        }
    }

    // (3) An Euler path must include every edge.
    if (numEdges(g) != nE) {
        return false;
    }

    // (4) An Euler path must include each edge exactly once, i.e. if
    //     the edge u -> v appears in the path, it cannot appear again.
    //     However, since g is undirected, it also means that v -> u
    //     can't appear either -- they're actually the same edge.
    for (int i = 0; i < nE; i++) {
        for (int j = i + 1; j < nE; j++) {
            // Situation 1: u -> v present twice
            if (e[i].start == e[j].start && e[i].end == e[j].end) {
                return false;
            }

            // Situation 2: both u -> v and v -> u present
            if (e[i].start == e[j].end && e[i].end == e[j].start) {
                return false;
            }
        }
    }

    return true;
}


int main(void) {
    // The path 0 -> 1 -> 2, which is an Euler path in graph 1.
    Edge path1[] = {
        { .start = 0, .end = 1 },
        { .start = 1, .end = 2 }
    };

    // The same path, which is not an Euler path in graph 2 since
    // it only contains 2 of its 3 edges.
    Edge *path2 = path1;

    // The path 0 -> 2 -> 3 -> 2 -> 1, which is not an Euler path in
    // graph 3. This graph cannot have an Euler path, since all of its
    // 4 vertices have odd degree.
    Edge path3[] = {
        { .start = 0, .end = 2 },
        { .start = 2, .end = 3 },
        { .start = 3, .end = 2 },
        { .start = 2, .end = 1}
    };

    // The path 0 -> 1 -> 2 -> 0 -> 3 -> 1, which is not an Euler path
    // in graph 4. Similarly to graph 3, it cannot have an Euler path.
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
