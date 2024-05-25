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


void 
test_addEdge() {
    int vertexCount = getRandomValue();
    Graph *graph = initGraph(vertexCount);
    assert(graph != NULL);

    int origin = rand() % vertexCount;
    int destiny;
    do {
        destiny = rand() % vertexCount;
    } while (destiny == origin);

    int weight = getRandomValue();
    addEdge(graph, origin, destiny, weight);

    Edge *edge = graph->vertices[origin].edges;
    assert(edge != NULL); 
    int found = 0;
    while (edge != NULL) {
        if (edge->destiny == destiny && edge->weight == weight) {
            found = 1;
            break;
        }
        edge = edge->next;
    }

    assert(found == 1);

    int new_origin, new_destiny;
    do {
        new_origin = rand() % vertexCount;
        new_destiny = rand() % vertexCount;
    } while ((new_origin == new_destiny) || (new_origin == origin && new_destiny == destiny));

    int new_weight = getRandomValue();
    addEdge(graph, new_origin, new_destiny, new_weight);

    found = 0;
    Edge *new_edge = graph->vertices[new_origin].edges;
    while (new_edge != NULL) {
        if (new_edge->destiny == new_destiny && new_edge->weight == new_weight) {
            found = 1;
            break;
        }
        new_edge = new_edge->next;
    }

    assert(found == 1);
}

int 
main() 
{
    test_initGraph();
    test_freeGraph();
    test_addEdge();
    return 0;
}
