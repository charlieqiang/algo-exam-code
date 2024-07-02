#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXV 2

struct MGraph
{
    int numVertices, numEdges;
    char VerticesList[MAXV];
    int Edge[MAXV][MAXV];
};

int printVertices(struct MGraph G);

int main()
{
    struct MGraph graph;
    graph.numVertices = MAXV;
    graph.numEdges = MAXV;
    strcpy(graph.VerticesList, "ab");
    int edge[MAXV][MAXV] = {{0, 1}, {0, 0}};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            graph.Edge[i][j] = edge[i][j];
        }
    }
    printf("%d\n", printVertices(graph));
    return (0);
}

int printVertices(struct MGraph G)
{
    int indegree, outdegree, k, m, count = 0;
    for (k = 0; k < G.numVertices; k++)
    {
        indegree = outdegree = 0;
        for (m = 0; m < G.numVertices; m++)
        {
            outdegree += G.Edge[k][m];
        }

        for (m = 0; m < G.numVertices; m++)
        {
            indegree += G.Edge[m][k];
        }

        if (outdegree > indegree)
        {
            printf("%c\n", G.VerticesList[k]);
            count++;
        }
    }
    return count;
}