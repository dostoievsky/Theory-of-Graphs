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
freeGraph(Graph* graph)
{
    for (int i = 0; i < graph->vertexCount; i++)
    {
        Edge* edge = graph->vertices[i].edges;
        while (edge)
        {
            Edge* temp = edge;
            edge = edge->next;
            free(temp);
        }
    }
    free(graph->vertices);
    free(graph);
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
    /*
    create an empty queue
    mark graph->verticies[index].visited = 1;
    insert graph->verticies[index] on queue;
    while queue is not empty
        pop queue
        for each neighbor w of v do
            if w is not visited then 
                visit the edge {v,w}
                push w in queue
                visit w
            else
               if {v,w} is not visited 
                   visit {v,w}
               endif
            endif
        endfor 
    endwhile
    */
}

void 
initQueue(Queue* q, int size) {
    q->items = (Vertex*)malloc(sizeof(Vertex) * size);  
    q->capacity = size;
    q->front = 0;
    q->rear = -1;      
    q->size = 0;
}


void 
enqueue(Queue* q, Vertex element) {
    q->rear = (q->rear + 1) % q->capacity; 
    q->items[q->rear] = element; 
    q->size++;
}

void
dequeue(Queue* q, Vertex* element) {
    *element = q->items[q->front]; 
    q->front = (q->front + 1) % q->capacity; 
    q->size--;
}

void 
freeQueue(Queue* q) {
    free(q->items); 
    q->items = NULL;
    q->capacity = 0;
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}
