#include "BFS.h"

Graph*
initGraph(int vertexCount)
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertexCount = vertexCount;
    graph->vertices = (Vertex*)malloc(sizeof(Vertex) * vertexCount);
    for (int i = 0; i < vertexCount; i++)
    {
        graph->vertices[i].edges = NULL;
        graph->vertices[i].visited = 0;
    }
    return graph;
}

void
freeGraph(Graph** graphPtr)
{
    if (graphPtr && *graphPtr) {
        Graph* graph = *graphPtr;
        for (int i = 0; i < graph->vertexCount; i++) {
            Edge* edge = graph->vertices[i].edges;
            while (edge) {
                Edge* temp = edge;
                edge = edge->next;
                free(temp);
            }
        }
        free(graph->vertices);
        free(graph);
        *graphPtr = NULL;
    }
}

void 
addEdge(Graph* graph, int origin, int destiny, int weight)
{
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->destiny = destiny;
    newEdge->weight = weight;
    newEdge->next = NULL;

    Edge** edgePtr = &graph->vertices[origin].edges;
    while (*edgePtr != NULL) {
        edgePtr = &(*edgePtr)->next;
    }
    *edgePtr = newEdge;
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
BFS(Graph* graph, int startIndex, Queue* path)
{
    Queue q;
    initQueue(&q, graph->vertexCount);

    graph->vertices[startIndex].visited = 1;
    enqueue(&q, &(graph->vertices[startIndex]));

    if (path != NULL) {
        enqueue(path, (void *)(size_t)startIndex);
    }

    while (!isQueueEmpty(&q)) {
        Vertex *currentVertex;
        dequeue(&q, (void **)&currentVertex);
        
        Edge *edge = currentVertex->edges;
        while (edge) {
            if (!graph->vertices[edge->destiny].visited) {
                graph->vertices[edge->destiny].visited = 1;
                enqueue(&q, &(graph->vertices[edge->destiny]));

                if (path != NULL) {
                    enqueue(path, (void *)(size_t)edge->destiny);
                }
            }
            edge = edge->next;
        }
    }

    freeQueue(&q);
}
