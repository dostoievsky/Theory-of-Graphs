#include <assert.h>
#include <stdlib.h>
#include "BFS.h"

void test_initGraph() {
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

int main() {
    test_initGraph();
    return 0;
}
