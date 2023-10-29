#include <stdbool.h>
#include <stdio.h>

#include "Graph.h"

typedef struct edge {
    Vertex start;
    Vertex end;
} Edge;

static Graph build_g1(void);
static Graph build_g2(void);
static Graph build_g3(void);
static Graph build_g4(void);

/** Prints a path on one line. */
static void print_path(Edge *path, int size);

/**
 * Given a graph and a list of edges representing a path, determines whether
 * it is an Euler path.
 */
bool is_euler_path(Graph g, Edge *path, int length) {
    // An Euler path needs to be as long as how many edges the graph has.
    if (length != graph_num_edges(g)) {
        return false;
    }

    // We need to check that the path's edges are actually edges in the graph.
    for (int i = 0; i < length; i++) {
        if (!graph_adjacent(g, path[i].start, path[i].end)) {
            return false;
        }
    }

    // The path actually has to be a path.
    for (int i = 0; i < length - 1; i++) {
        if (path[i].end != path[i + 1].start) {
            return false;
        }
    }

    // Each edge can appear only once. Note that if we've already used the edge
    // u -> v, then we can't use the reversed edge v -> u either.
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if (path[i].start == path[j].start && path[i].end == path[j].end) {
                return false;
            } else if (path[i].start == path[j].end &&
                       path[i].end == path[j].start) {
                return false;
            }
        }
    }

    // If we haven't failed any checks, it's a valid Euler path!
    return true;
}

int main(void) {
    // The path 0 -> 1 -> 2, which is an Euler path in graph 1.
    Edge path1[] = {{.start = 0, .end = 1}, {.start = 1, .end = 2}};

    // The same path, which is not an Euler path in graph 2 since it only
    // contains 2 of its 3 edges.
    Edge *path2 = path1;

    // The path 0 -> 2 -> 3 -> 2 -> 1, which is not an Euler path in
    // graph 3. Graph 3 cannot have any Euler paths, since all of its
    // vertices have odd degree.
    Edge path3[] = {{.start = 0, .end = 2},
                    {.start = 2, .end = 3},
                    {.start = 3, .end = 2},
                    {.start = 2, .end = 1}};

    // The path 0 -> 1 -> 2 -> 0 -> 3 -> 1, which is not an Euler path in
    // graph 4. Similarly to graph 3, it cannot have any Euler paths.
    Edge path4[] = {{.start = 0, .end = 1},
                    {.start = 1, .end = 2},
                    {.start = 2, .end = 0},
                    {.start = 0, .end = 3},
                    {.start = 3, .end = 1}};

    Graph g1 = build_g1();
    Graph g2 = build_g2();
    Graph g3 = build_g3();
    Graph g4 = build_g4();

    print_path(path1, 2);
    printf("Is this an Euler path in graph 1? %s\n\n",
           is_euler_path(g1, path1, 2) ? "yes" : "no");

    print_path(path2, 2);
    printf("Is this an Euler path in graph 2? %s\n\n",
           is_euler_path(g2, path2, 2) ? "yes" : "no");

    print_path(path3, 4);
    printf("Is this an Euler path in graph 3? %s\n\n",
           is_euler_path(g3, path3, 4) ? "yes" : "no");

    print_path(path4, 5);
    printf("Is this an Euler path in graph 4? %s\n",
           is_euler_path(g4, path4, 5) ? "yes" : "no");

    return 0;
}

static Graph build_g1(void) {
    Graph g = graph_new(3);
    graph_insert_edge(g, 0, 1);
    graph_insert_edge(g, 1, 2);
    return g;
}

static Graph build_g2(void) {
    Graph g = build_g1();
    graph_insert_edge(g, 2, 0);
    return g;
}

static Graph build_g3(void) {
    Graph g = graph_new(4);
    graph_insert_edge(g, 0, 2);
    graph_insert_edge(g, 1, 2);
    graph_insert_edge(g, 2, 3);
    return g;
}

static Graph build_g4(void) {
    Graph g = build_g3();
    graph_insert_edge(g, 0, 1);
    graph_insert_edge(g, 0, 3);
    graph_insert_edge(g, 1, 3);
    return g;
}

static void print_path(Edge *path, int length) {
    printf("%d", path[0].start);
    for (int i = 0; i < length; i++) {
        printf(" -> %d", path[i].end);
    }
    printf("\n");
}
