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
    Graph *graph = initGraph(vertexCount, 0);
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
        new_origin = (rand() % vertexCount);
        new_destiny = (rand() % vertexCount);
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
test_BFS_NullPath()
{
    int vertexCount = 4;
    Graph *graph = initGraph(vertexCount, 0);
    
    addEdge(graph, 0, 1, 1);
    addEdge(graph, 0, 2, 1);
    addEdge(graph, 0, 3, 1);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 3, 1);
    addEdge(graph, 2, 3, 1);

    BFS(graph, 0, NULL);

    for (int i = 0; i < vertexCount; i++) {
        assert(graph->vertices[i].visited == 1);
    }

    freeGraph(&graph);
}

void 
test_BFS_WithPath() 
{
    int vertexCount = 4;
    Graph *graph = initGraph(vertexCount, 0);
    
    addEdge(graph, 0, 1, 1);
    addEdge(graph, 0, 2, 1);
    addEdge(graph, 0, 3, 1);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 3, 1);
    addEdge(graph, 2, 3, 1);

    Queue path;
    initQueue(&path, graph->vertexCount);
    BFS(graph, 0, &path);

    int vertexIndex;
    void *item;
    for (int i = 0; i < vertexCount; i++) {
        assert(graph->vertices[i].visited == 1);
        dequeue(&path, &item);
        vertexIndex = (int)(size_t)item;
        assert(vertexIndex == i);
    }

    freeGraph(&graph);
    freeQueue(&path);
}


void 
test_BFS_Directed_NotAllVisited()
{
    int vertexCount = 4;
    Graph *graph = initGraph(vertexCount, 1);
    
    addEdge(graph, 0, 1, 1);
    addEdge(graph, 1, 2, 1);

    Queue path;
    initQueue(&path, graph->vertexCount);
    BFS(graph, 0, &path);

    assert(graph->vertices[0].visited == 1);
    assert(graph->vertices[1].visited == 1);
    assert(graph->vertices[2].visited == 1);
    assert(graph->vertices[3].visited == 0);

    int visitedOrder[] = {0, 1, 2};
    void *item;
    for (int i = 0; i < 3; i++) {
        dequeue(&path, &item);
        int vertexIndex = (int)(size_t)item;
        assert(vertexIndex == visitedOrder[i]);
    }

    assert(isQueueEmpty(&path));

    freeGraph(&graph);
    freeQueue(&path);
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

    test_BFS_NullPath();
    test_BFS_WithPath();
    test_BFS_Directed_NotAllVisited();

    return 0;
}
