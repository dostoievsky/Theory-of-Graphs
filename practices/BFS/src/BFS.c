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
freeGraph(Graph** graphPtr) {
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
    newEdge->next = graph->vertices[origin].edges;
    graph->vertices[origin].edges = newEdge;
}

void
BFS(Graph* graph, int index)
{
    Queue q;
    initQueue(&q, graph->vertexCount);
    graph->vertices[index].visited = 1;
    enqueue(&q, graph->vertices[index]);
    while(!isQueueEmpty(&q))
    {
        Vertex* vertex;
        dequeue(&q, vertex);
        Edge* edge = vertex->edges;
        while (edge)
        {
            if (!graph->vertices[edge->destiny].visited) 
            {
                graph->vertices[edge->destiny].visited = 1;
                enqueue(&q, graph->vertices[edge->destiny]);
            }
            edge = edge->next;
        }
    }
    freeQueue(&q);
}

void 
initQueue(Queue* q, int size) 
{
    q->items = (Vertex*)malloc(sizeof(Vertex) * size);  
    q->capacity = size;
    q->front = 0;
    q->rear = -1;      
    q->size = 0;
}


void 
enqueue(Queue* q, Vertex element) 
{
    q->rear = (q->rear + 1) % q->capacity; 
    q->items[q->rear] = element; 
    q->size++;
}

void
dequeue(Queue* q, Vertex* element)
{
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
initstack(Stack *s) 
{
    s->items = NULL;
    s->top = -1;
}

void 
push(Stack *s, int item) 
{
    int newTop = s->top + 1;
    int *newItems = realloc(s->items, (newTop + 1) * sizeof(int));
    s->items = newItems;
    s->items[newTop] = item;
    s->top = newTop;
}

void 
pop(Stack *s, int *item) 
{
    if (isStackEmpty(s)) { return; }

    *item = s->items[s->top];
    s->top--;

    if (s->top >= 0) 
    {
        int *newItems = realloc(s->items, (s->top + 1) * sizeof(int));
        if (newItems) {
            s->items = newItems;
        }
    } else {
        free(s->items);
        s->items = NULL;
    }

}

void freeStack(Stack *s) 
{
    free(s->items);
    s->items = NULL;
    s->top = -1;
}
