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
