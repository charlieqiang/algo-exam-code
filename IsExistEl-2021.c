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

int isExistEl(struct MGraph G);

int main()
{
    struct MGraph graph;
    graph.numVertices = MAXV;
    graph.numEdges = MAXV;
    strcpy(graph.VerticesList, "abcde");
    int edge[MAXV][MAXV] = {{0, 1, 1, 0, 0}, {1, 0, 0, 1, 1}, {1, 0, 0, 1, 0}, {0, 1, 1, 0, 0}, {0, 1, 0, 0, 0}};
    for (int i = 0; i < MAXV; i++)
    {
        for (int j = 0; j < MAXV; j++)
        {
            graph.Edge[i][j] = edge[i][j];
        }
    }
    printf("%d\n", isExistEl(graph));
    return (0);
}

int isExistEl(struct MGraph G)
{
    int degree, count = 0;
    for (int i = 0; i < G.numVertices; i++)
    {
        degree = 0;
        for (int j = 0; j < G.numVertices; j++)
        {
            degree += G.Edge[i][j];
        }
        if (degree % 2 != 0)
        {
            count++;
        }
    }
    return count == 0 || count == 2;
}