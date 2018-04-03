//
// Created by h2279 on 2018/04/03.
//

#ifndef SHORTESTPATHALGORITHMWITHHEAPS_DIJKSTRA_H
#define SHORTESTPATHALGORITHMWITHHEAPS_DIJKSTRA_H

#define MAX 10005
#define INFINITY 1000005

#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;
// 邻接矩阵
typedef struct _graph {
    char vexs[MAX];       // 顶点集合
    int vexnum;           // 顶点数
    int edgnum;           // 边数
    int matrix[MAX][MAX]; // 邻接矩阵
} Graph, *PGraph;

// 边的结构体
typedef struct _EdgeData {
    char start; // 边的起点
    char end;   // 边的终点
    int weight; // 边的权重
} EData;

typedef struct node {
    int u, dis;

    bool operator<(const node &a) const {
        return a.dis < dis;
    }//head重载 < ，以 dis 从小到大排列
};
/*
 * first line, the number of vex v
 * then, the number of edge e
 * followed by e lines: length ,start, end
 */
Graph create_graph();
void dijkstra(Graph G, int vs, int prev[], int dist[]);

#endif //SHORTESTPATHALGORITHMWITHHEAPS_DIJKSTRA_H
