#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Set.h"


static Graph generateGraph(void);


/** A fairly standard recursive DFS. No tricks here. */
static void reachableDFS(Graph g, Vertex v, Set s) {
    addToSet(s, v);

    int nV = numVertices(g);
    for (Vertex w = 0; w < nV; w++) {
        if (connected(g, v, w) && !setContains(s, w)) {
            reachableDFS(g, w, s);
        }
    }
}

Set reachable(Graph g, Vertex src) {
    // All we have to do is pick our favourite graph traversal and
    // run it on the graph, keep track of what we visited in a set
    // and then return that set.
    // A DFS is nice and easy to implement recursively without needing
    // to code up a stack ADT, so we'll do that. An iterative DFS or a
    // BFS would work for this problem though - it's just that DFS is
    // probably the one you'd choose if you had no special conditions.
    Set s = newSet(numVertices(g));
    reachableDFS(g, src, s);
    return s;
}


int main(int argc, char **argv) {
    Graph g = generateGraph();

    Set s1 = reachable(g, 0);
    printf("Reachable from 0: ");
    showSetContents(s1);

    Set s2 = reachable(g, 1);
    printf("Reachable from 1: ");
    showSetContents(s2);

    Set s3 = reachable(g, 5);
    printf("Reachable from 5: ");
    showSetContents(s3);

    Set s4 = reachable(g, 6);
    printf("Reachable from 6: ");
    showSetContents(s4);

    return 0;
}


static Graph generateGraph(void) {
    Graph g = buildGraph(10);
    insertEdge(g, 0, 1);
    insertEdge(g, 0, 2);
    insertEdge(g, 0, 3);
    insertEdge(g, 2, 1);
    insertEdge(g, 2, 3);
    insertEdge(g, 2, 4);
    insertEdge(g, 2, 5);
    insertEdge(g, 3, 0);
    insertEdge(g, 3, 4);
    insertEdge(g, 4, 2);
    insertEdge(g, 4, 5);
    insertEdge(g, 4, 7);
    insertEdge(g, 4, 8);
    insertEdge(g, 5, 1);
    insertEdge(g, 6, 5);
    insertEdge(g, 6, 7);
    insertEdge(g, 6, 9);
    insertEdge(g, 7, 4);
    insertEdge(g, 7, 5);
    insertEdge(g, 7, 8);
    insertEdge(g, 8, 7);
    insertEdge(g, 9, 7);
    insertEdge(g, 9, 8);

    return g;
}
