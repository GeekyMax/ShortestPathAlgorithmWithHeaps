//
// Created by h2279 on 2018/04/03.
//

#ifndef SHORTESTPATHALGORITHMWITHHEAPS_DIJKSTRA_H
#define SHORTESTPATHALGORITHMWITHHEAPS_DIJKSTRA_H

#define MAX 10005
#define INFINITY 1000005

#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include "FibonacciHeap.h"
#include "DefaultHeap.h"
using namespace std;

typedef struct _graph {
    int vertex_num;           // 顶点数
    int edge_num;           // 边数
    int matrix[MAX][MAX]; // 邻接矩阵
} *Graph;

/*
 * first line, the number of vex v
 * then, the number of edge e
 * followed by e lines: length ,start, end
 */
Graph create_graph();

void dijkstra(Heap *heap, Graph G, int vs, int *prev, int *dist);

#endif //SHORTESTPATHALGORITHMWITHHEAPS_DIJKSTRA_H
