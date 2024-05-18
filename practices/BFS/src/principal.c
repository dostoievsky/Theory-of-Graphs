#include <stdio.h>
#include "BFS.h"

int 
main(int argc, char *argv[])
{
    int n, m, b, i;
    scanf("%d %d %d %d", &n, &m, &b, &i);
    Graph* graph = initGraph(m);
    for (int j = 0; j < m; j++)
    {
        int o, d, p;
        scanf("%d %d %d", &o, &d, &p);
        addEdge(graph, o, d, p);
    }
    BFS(graph, i);
    freeGraph(graph); 
    return 0;
}
