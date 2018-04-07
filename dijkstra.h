//
// Created by h2279 on 2018/04/03.
//

#ifndef SHORTESTPATHALGORITHMWITHHEAPS_DIJKSTRA_H
#define SHORTESTPATHALGORITHMWITHHEAPS_DIJKSTRA_H

#include "base.h"
#include "Heap.h"

using namespace std;
typedef struct _adjacentNode {
    int end;
    Type length;
    struct _adjacentNode* next;
} *adjacentNode;

typedef struct _graph {
    int vertex_num;           // 顶点数
    int edge_num;           // 边数
    adjacentNode head[MAX]; // 邻接矩阵
} *Graph;


/**
 * first line, the number of vex v
 * then, the number of edge e
 * followed by e lines: length ,start, end
 * @return a graph
 */
Graph create_graph();

/**
 * @param heap a heap used for find min dist.
 * @param G the input graph
 * @param vs the source point
 * @param prev an array to store the each node's prev node
 * @param dist an array to store the distance of each node
 */
void dijkstra(Heap *heap, Graph G, int vs, int *prev, int *dist);

#endif //SHORTESTPATHALGORITHMWITHHEAPS_DIJKSTRA_H
