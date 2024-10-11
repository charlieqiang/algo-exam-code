#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXV 5

struct MGraph
{
    int numVertices, numEdges;
    char VerticesList[MAXV];
    int Edge[MAXV][MAXV];
};

int uniquely(struct MGraph G);

int main()
{
    struct MGraph graph;
    graph.numVertices = MAXV;
    graph.numEdges = MAXV;
    strcpy(graph.VerticesList, "abcde");
    int edge[MAXV][MAXV] = {{0, 1, 1, 0, 0}, {0, 0, 0, 1, 0}, {0, 0, 0, 1, 0}, {0, 0, 0, 0, 1}, {0, 0, 0, 0, 0}};
    for (int i = 0; i < MAXV; i++)
    {
        for (int j = 0; j < MAXV; j++)
        {
            graph.Edge[i][j] = edge[i][j];
        }
    }
    printf("%d\n", uniquely(graph));
    return (0);
}

int uniquely(struct MGraph G)
{
    int inDegree[MAXV] = {0};

    for (int i = 0; i < G.numVertices; i++)
    {
        for (int j = 0; j < G.numVertices; j++)
        {
            if (G.Edge[i][j] > 0)
            {
                inDegree[j]++;
            }
        }
    }

    int count, u;
    for (int i = 0; i < G.numVertices; i++)
    {
        count = 0;
        for (int j = 0; j < G.numVertices; j++)
        {
            if (inDegree[j] == 0)
            {
                u = j;
                count++;
            }
        }

        if (count != 1)
        {
            return 0;
        }

        inDegree[u] = -1;
        for (int j = 0; j < G.numVertices; j++)
        {
            if (G.Edge[u][j] != 0)
            {
                --inDegree[j];
            }
        }
    }
    return 1;
}