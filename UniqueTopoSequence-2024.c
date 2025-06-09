#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @file UniqueTopoSequence-2024.c
 * @brief 有向图邻接矩阵，求拓扑排序是否唯一
 * 设计思想：
 * 1. 计算每个顶点的入度。
 * 2. 使用 Kahn 算法进行拓扑排序，检查在每一步中是否有唯一的入度为 0 的顶点。
 * 3. 如果在任何一步中有多个顶点的入度为 0，则拓扑排序不是唯一的。
 * 4. 如果所有顶点都被处理且每一步都有唯一的入度为 0 的顶点，则拓扑排序是唯一的。
 * * @note
 * 有向图邻接矩阵，求拓朴排序是否唯一
 * 已知图 G 采用邻接矩阵存储是，其定义如下
 * Typedef struct{ //图的类型
 * Int numberVertices,numEgges; // 图的顶点数和有向边数
 * Char VerticesList[maxV]; // 顶点表,MAXV 为已定义常量
 * Int edge[maxV][maxV]; //邻接矩阵
 * }MGraph;
 * 判断 G 是否有唯一的拓扑序列，是 1 否返回 0
 * (1)给出算法的设计思想。
 * (2)根据算法思想，写出 C/C++描述，并注释。
 */
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