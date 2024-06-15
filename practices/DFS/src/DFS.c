#include "DFS.h"

Graph*
initGraph(int vertexCount, int type)
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertexCount = vertexCount;
    graph->type = type;
    graph->vertices = (Vertex**) malloc(sizeof(Vertex*) * vertexCount);

    for (int i = 0; i < vertexCount; i++)
    {
        graph->vertices[i] = (Vertex*) malloc(sizeof(Vertex) * vertexCount);
        for (int j = 0; j < vertexCount; j++) 
        {
            graph->vertices[i][j].connected = 0;
            graph->vertices[i][j].weight = 0;
            graph->vertices[i][j].visited = 0;
        }
    }
    return graph;
}

void
freeGraph(Graph** graphPtr)
{
    if (graphPtr && *graphPtr) 
    {
        Graph* graph = *graphPtr;
        free(graph->vertices);
        free(graph);
        *graphPtr = NULL;
    }
}

void 
addEdge(Graph* graph, int origin, int destiny, int weight)
{
    graph->vertices[origin][destiny].connected = 1;
    graph->vertices[origin][destiny].weight = weight;
    if (graph->type == 0) 
    {
        graph->vertices[destiny][origin] = graph->vertices[origin][destiny];
    }
}

void 
initQueue(Queue* q, int size)
{
    q->items = (void**)malloc(sizeof(void*) * size);  
    q->capacity = size;
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

void 
enqueue(Queue* q, void* element)
{
    if (q->size == q->capacity) {
        return;
    }

    q->rear = (q->rear + 1) % q->capacity;
    q->items[q->rear] = element;
    q->size++;
}

void 
dequeue(Queue* q, void** element)
{
    if (q->size == 0) {
        *element = NULL;
        return;
    }

    *element = q->items[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
}

void 
freeQueue(Queue* q) 
{
    free(q->items); 
    q->items = NULL;
    q->capacity = 0;
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

void 
DFS(Graph* graph, int startIndex, Queue* path)
{

}
