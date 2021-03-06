#include <stdio.h>

#include "Graph.h"


typedef struct edge {
    Vertex start;
    Vertex end;
} Edge;


/** Generate graphs from Q9. */
static Graph generate_graph1(void);
static Graph generate_graph2(void);
static Graph generate_graph3(void);
static Graph generate_graph4(void);

/** Prints a path on one line. */
static void  print_path(Edge *, int);


/** Determines whether a given path is an Euler path of a graph. */
bool is_euler_path(Graph g, Edge *e, int nE) {
    // TODO: Complete this function!
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

    Graph g1 = generate_graph1();
    Graph g2 = generate_graph2();
    Graph g3 = generate_graph3();
    Graph g4 = generate_graph4();

    print_path(path1, 2);
    printf(
        "Is this an Euler path in graph 1? %s\n\n",
        is_euler_path(g1, path1, 2) ? "yes" : "no"
    );

    print_path(path2, 2);
    printf(
        "Is this an Euler path in graph 2? %s\n\n",
        is_euler_path(g2, path2, 2) ? "yes" : "no"
    );

    print_path(path3, 4);
    printf(
        "Is this an Euler path in graph 3? %s\n\n",
        is_euler_path(g3, path3, 4) ? "yes" : "no"
    );

    print_path(path4, 5);
    printf(
        "Is this an Euler path in graph 4? %s\n",
        is_euler_path(g4, path4, 5) ? "yes" : "no"
    );

    return 0;
}


static Graph generate_graph1(void) {
    Graph g = build_graph(3);
    insert(g, 0, 1);
    insert(g, 1, 2);
    return g;
}

static Graph generate_graph2(void) {
    Graph g = generate_graph1();
    insert(g, 2, 0);
    return g;
}

static Graph generate_graph3(void) {
    Graph g = build_graph(4);
    insert(g, 0, 2);
    insert(g, 1, 2);
    insert(g, 2, 3);
    return g;
}

static Graph generate_graph4(void) {
    Graph g = generate_graph3();
    insert(g, 0, 1);
    insert(g, 0, 3);
    insert(g, 1, 3);
    return g;
}

static void print_path(Edge *e, int nE) {
    printf("%d", e[0].start);
    for (int i = 0; i < nE; i++) {
        printf(" -> %d", e[i].end);
    }
    printf("\n");
}
