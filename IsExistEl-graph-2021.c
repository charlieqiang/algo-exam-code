#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @file IsExistEl-2021.c
 * @brief 判断图是否有欧拉路径或回路
 * 已知无向连通图 G 由顶点集 V 和边集 E 组成|E|>0，当 G 中度为奇数的顶点个数 为不大于 2 的偶数时，
 * G 存在包含所有边且长度为|E|的路径(称为 EL 路径)，设图 G 采用邻接 矩阵存储
 *
 * 类型定义如下：
 * typedef struct{ //图的类型
 * int numVertices,numEdges; // 图的顶点数和边数
 * Char VerticesList[MAXV]; // 顶点表,MAXV 为已定义常量
 * int Edge[MAXV][MAXV]; //邻接矩阵
 * }MGraph;
 *
 * 请设计算法：int IsExistEL(MGraph G)，判断 G 是否存在 EL 路径，若存在，则返回 1，否则，返回 0
 */

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