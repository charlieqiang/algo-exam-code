#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 对于有向图，如果一个顶点的出度大于入度，则这个顶点称为K顶点，有向图用邻接矩阵存储，数据结构定义如下:
 * typedef struct{
 * int numVertex, numEdge;//顶点数，边数
 * char VertexList[MAXV];//顶点表
 * int Edge[MAXV][MAXV];//邻接矩阵
 * }MGraph;
 *
 * 要求实现函数int printVertices(MGraph G)，输出有向图中所有K顶点，并返回K顶点的总数
 */
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