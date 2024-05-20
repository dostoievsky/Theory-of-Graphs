#include <assert.h>
#include <time.h>
#include <stdlib.h>

#include "BFS.h"

#define RANDOM_MAX 1000

int
getRandomValue()
{
    srand(time(NULL));
    return rand() % RANDOM_MAX + 1;
}

void 
test_initGraph()
{
    int vertexCount = getRandomValue();
    Graph *graph = initGraph(vertexCount);
    assert(graph != NULL);
    assert(graph->vertexCount == vertexCount);
    for (int i = 0; i < vertexCount; i++) {
        assert(graph->vertices[i].edges == NULL);
        assert(graph->vertices[i].visited == 0);
    }
}

void 
test_freeGraph()
{
    int vertexCount = getRandomValue();
    Graph *graph = initGraph(vertexCount);
    assert(graph != NULL);
    assert(graph->vertexCount == vertexCount);
    freeGraph(&graph);
    assert(graph == NULL);
}

int 
main() 
{
    test_initGraph();
    test_freeGraph();
    return 0;
}
