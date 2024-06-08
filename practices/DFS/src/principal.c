#include <stdio.h>
#include "DFS.h"

int
main(int argc, char *argv[])
{
    int n, m, b, i;

    scanf("%d %d %d %d", &n, &m, &b, &i);

    Graph* graph = initGraph(m, b);

    for (int j = 0; j < m; j++) {
        int o, d, p;
        scanf("%d %d %d", &o, &d, &p);
        addEdge(graph, o-1, d-1, p);
    }

    Queue path;
    initQueue(&path, graph->vertexCount);

    BFS(graph, i-1, &path);

    int vertexIndex;
    void *item;
    while (!isQueueEmpty(&path)) {
        dequeue(&path, &item);
        vertexIndex = (int)(size_t)item;
        printf("%d\n", vertexIndex + 1);
    }

    freeGraph(&graph);
    freeQueue(&path);

    return 0;
}
