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
    struct Vertex* items;        
    int capacity;     
    int front;       
    int rear;          
    int size;          
} Queue;

typedef struct {
    int *items;
    int top;
} Stack;

Graph* initGraph(int vertexCount);
void freeGraph(Graph* graph);
void addEdge(Graph* graph, int origin, int destiny, int weight);
void BFS(Graph* graph, int index);

void initQueue(Queue* q, int size);
void enqueue(Queue* q, Vertex element);
void dequeue(Queue* q, Vertex* element);
static inline int isQueueEmpty(const Queue* q) { return q->size == 0; }
void freeQueue(Queue* q);

void initstack(Stack *s);
static inline int isStackEmpty(Stack *s) { return s->top == -1; }
void push(Stack *s, int item);
void pop(Stack *s, int *item);
void freeStack(Stack *s);
