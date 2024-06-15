#include <assert.h>
#include <time.h>
#include <stdlib.h>

#include "DFS.h"

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
    Graph *graph = initGraph(vertexCount, 0);
    assert(graph != NULL);
    assert(graph->vertexCount == vertexCount);
    for (int i = 0; i < vertexCount; i++) 
    {
        for (int j = 0; j < vertexCount; j++) 
        {
            assert(graph->vertices[i][j].connected == 0);
            assert(graph->vertices[i][j].weight == 0);
            assert(graph->vertices[i][j].visited == 0);
        }
    }
}

void 
test_freeGraph()
{
    int vertexCount = getRandomValue();
    Graph *graph = initGraph(vertexCount, 0);
    assert(graph != NULL);
    assert(graph->vertexCount == vertexCount);
    freeGraph(&graph);
    assert(graph == NULL);
}


void 
test_addEdge()
{
    int vertexCount = getRandomValue();
    Graph *graph = initGraph(vertexCount, 0);
    assert(graph != NULL);

    int origin, destiny;
    do {
        origin = (rand() % vertexCount);
        destiny = (rand() % vertexCount);
    } while (destiny == origin);

    int weight = getRandomValue();
    addEdge(graph, origin, destiny, weight);
    assert(graph->vertices[origin][destiny].connected == 1);

    int new_origin, new_destiny;
    do {
        new_origin = (rand() % vertexCount);
        new_destiny = (rand() % vertexCount);
    } while ((new_origin == new_destiny) || (new_origin == origin && new_destiny == destiny));

    int new_weight = getRandomValue();
    addEdge(graph, new_origin, new_destiny, new_weight);
    assert(graph->vertices[new_origin][new_destiny].connected == 1);
}

void 
test_initQueue() 
{
    int size = getRandomValue();
    Queue queue;
    initQueue(&queue, size);
    assert(queue.items != NULL);
    assert(queue.capacity == size);
    assert(queue.front == 0);
    assert(queue.rear == -1);
    assert(queue.size == 0);
    free(queue.items);
}

void 
test_enqueue() 
{
    Queue queue;
    initQueue(&queue, 2);
    Vertex *v1 = malloc(sizeof(Vertex));
    Vertex *v2 = malloc(sizeof(Vertex));
    enqueue(&queue, v1);
    assert(queue.rear == 0);
    assert(queue.size == 1);
    enqueue(&queue, v2);
    assert(queue.rear == 1);
    assert(queue.size == 2);
    freeQueue(&queue);
}

void 
test_dequeue() 
{
    Queue queue;
    initQueue(&queue, 2);
    Vertex *v1 = malloc(sizeof(Vertex));
    Vertex *v2 = malloc(sizeof(Vertex));
    enqueue(&queue, v1);
    enqueue(&queue, v2);
    Vertex *element;
    dequeue(&queue, (void **)&element);
    assert(queue.front == 1);
    assert(queue.size == 1);
    assert(element == v1);
    dequeue(&queue, (void **)&element);
    assert(queue.front == 0);
    assert(queue.size == 0);
    assert(element == v2);
    freeQueue(&queue);
}

void 
test_freeQueue()
{
    Queue queue;
    initQueue(&queue, 2);
    freeQueue(&queue);
    assert(queue.items == NULL);
    assert(queue.capacity == 0);
    assert(queue.front == 0);
    assert(queue.rear == -1);
    assert(queue.size == 0);
}

void 
test_DFS_NullPath()
{

}

void 
test_DFS_WithPath() 
{

}

void 
test_DFS_Directed_NotAllVisited()
{

}

int 
main() 
{

    test_initGraph();
    test_freeGraph();
    test_addEdge();

    test_initQueue();
    test_enqueue();
    test_dequeue();
    test_freeQueue();


    test_DFS_NullPath();
    test_DFS_WithPath();
    test_DFS_Directed_NotAllVisited();

    return 0;
}
