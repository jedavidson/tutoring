#include <stdio.h>
#include <stdlib.h>

#include "Digraph.h"
#include "Set.h"

static Digraph generate_example_digraph(void);

static void dfs(Digraph g, Vertex v, Set s) {
    add_to_set(s, v);
    for (Vertex w = 0; w < digraph_num_vertices(g); w++) {
        if (digraph_adjacent(g, v, w) && !set_contains(s, w)) {
            dfs(g, w, s);
        }
    }
}

/** Computes the set of reachable vertices from a starting vertex. */
Set reachable(Digraph g, Vertex src) {
    Set s = new_set();
    add_to_set(s, src);
    dfs(g, src, s);
    return s;
}

int main(void) {
    Digraph g = generate_example_digraph();

    Set s1 = reachable(g, 0);
    printf("Reachable from 0: ");
    show_set(s1);

    Set s2 = reachable(g, 1);
    printf("Reachable from 1: ");
    show_set(s2);

    Set s3 = reachable(g, 5);
    printf("Reachable from 5: ");
    show_set(s3);

    Set s4 = reachable(g, 6);
    printf("Reachable from 6: ");
    show_set(s4);

    digraph_free(g);
    free_set(s1);
    free_set(s2);
    free_set(s3);
    free_set(s4);
    return EXIT_SUCCESS;
}

static Digraph generate_example_digraph(void) {
    Digraph g = digraph_new(10);
    digraph_insert_edge(g, 0, 1);
    digraph_insert_edge(g, 0, 2);
    digraph_insert_edge(g, 0, 3);
    digraph_insert_edge(g, 2, 1);
    digraph_insert_edge(g, 2, 3);
    digraph_insert_edge(g, 2, 4);
    digraph_insert_edge(g, 2, 5);
    digraph_insert_edge(g, 3, 0);
    digraph_insert_edge(g, 3, 4);
    digraph_insert_edge(g, 4, 2);
    digraph_insert_edge(g, 4, 5);
    digraph_insert_edge(g, 4, 7);
    digraph_insert_edge(g, 4, 8);
    digraph_insert_edge(g, 5, 1);
    digraph_insert_edge(g, 6, 5);
    digraph_insert_edge(g, 6, 7);
    digraph_insert_edge(g, 6, 9);
    digraph_insert_edge(g, 7, 4);
    digraph_insert_edge(g, 7, 5);
    digraph_insert_edge(g, 7, 8);
    digraph_insert_edge(g, 8, 7);
    digraph_insert_edge(g, 9, 7);
    digraph_insert_edge(g, 9, 8);
    return g;
}
