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

