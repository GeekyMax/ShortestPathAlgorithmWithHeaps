//
// Created by h2279 on 2018/04/03.
//

#include "dijkstra.h"

/**
 * first line, the number of vex v
 * then, the number of edge e
 * followed by e lines: length ,start, end
 * @return a graph
 */
Graph create_graph() {
    int length, start, end;
//    alloc the space gor graph
    Graph graph = (Graph) malloc(sizeof(struct _graph));
//    init the matrix
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            graph->matrix[i][j] = INF;
        }
    }
//    read the numbers
    cin >> graph->vertex_num >> graph->edge_num;
//    read each lines
    for (int i = 0; i < graph->edge_num; i++) {
        cin >> length >> start >> end;
        graph->matrix[start][end] = min(graph->matrix[start][end], length);
        graph->matrix[end][start] = min(graph->matrix[end][start], length);
    }
    return graph;
}

/**
 * @param heap a heap used for find min dist.
 * @param G the input graph
 * @param vs the source point
 * @param prev an array to store the each node's prev node
 * @param dist an array to store the distance of each node
 */
void dijkstra(Heap *heap, Graph G, int vs, int *prev, int *dist) {
//    clear the heap
    heap->clear();
//    this array store the flag of whether the node have found the min distance
    bool flag[MAX];
    for (int i = 0; i < G->vertex_num; ++i) {
        flag[i] = false;
        prev[i] = INF;
        dist[i] = INF;
    }
//    push first origin node to the priority queue
    heap->push(vs, 0);
//    if the heap is not empty, pop one key and then update all adjacent node's distance.
    while (!heap->empty()) {
        int u = heap->top().first;
        int dis = heap->top().second;
        heap->pop();
        if (flag[u]) {
            continue;
        }
        dist[u] = dis;
        flag[u] = true;
        for (int i = 0; i < G->vertex_num; i++) {
//            update the dist of this node's adjacent nodes
//            if we get a smaller dist, we will insert it to the heap
            if (G->matrix[u][i] + dis < dist[i]) {
                dist[i] = G->matrix[u][i] + dis;
                prev[i] = u;
                heap->push(i, dist[i]);
            }
        }
    }
}
