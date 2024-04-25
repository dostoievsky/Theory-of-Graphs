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

Graph* initGraph(int vertexCount);
void freeGraph(Graph* graph);
void addEdge(Graph* graph, int origin, int destiny, int weight);
void BFS(Graph* graph, int index);
