#include <stdlib.h>

typedef struct Edge
{
    int destiny;
    int weight;
    struct Edge* next;
} Edge;

typedef struct Vertex
{
    struct Edge* edges;
    int visited;
} Vertex;

typedef struct Graph 
{
    int vertexCount;
    struct Vertex* vertices;
} Graph;

typedef struct {
    void** items;
    int capacity;
    int front;
    int rear;
    int size;
} Queue;

Graph* initGraph(int vertexCount);
void freeGraph(Graph** graph);
void addEdge(Graph* graph, int origin, int destiny, int weight);

void initQueue(Queue* q, int size);
void enqueue(Queue* q, void* element);
void dequeue(Queue* q, void** element);
static inline int isQueueEmpty(const Queue* q) { return q->size == 0; }
void freeQueue(Queue* q);

void BFS(Graph* graph, int index, Queue* path);
