#include <assert.h>
#include <stdlib.h>
#include "BFS.h"

void 
test_initGraph() {
    int vertexCount = 5;
    Graph *graph = initGraph(vertexCount);
    assert(graph != NULL);
    assert(graph->vertexCount == vertexCount);
    for (int i = 0; i < vertexCount; i++) {
        assert(graph->vertices[i].edges == NULL);
        assert(graph->vertices[i].visited == 0);
    }
    free(graph->vertices);
    free(graph);
}


void 
test_freeGraph() {
    int vertexCount = 5;
    Graph *graph = initGraph(vertexCount);
    assert(graph != NULL);
    assert(graph->vertexCount == vertexCount);
    freeGraph(&graph);
    assert(graph == NULL);
}

int 
main() {
    test_initGraph();
    test_freeGraph();
    return 0;
}
