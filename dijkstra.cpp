//
// Created by h2279 on 2018/04/03.
//

#include "dijkstra.h"

Graph create_graph() {
    int length, start, end;
    Graph graph = (Graph) malloc(sizeof(struct _graph));
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            graph->matrix[i][j] = INF;
        }
    }
    cin >> graph->vertex_num >> graph->edge_num;
    for (int i = 0; i < graph->edge_num; i++) {
        cin >> length >> start >> end;
        graph->matrix[start][end] = min(graph->matrix[start][end], length);
        graph->matrix[end][start] = min(graph->matrix[end][start], length);
    }
    return graph;
}

void dijkstra(Heap *heap, Graph G, int vs, int *prev, int *dist) {
    heap->clear();
    bool flag[MAX];
    for (int i = 0; i < G->vertex_num; ++i) {
        flag[i] = false;
        prev[i] = INF;
        dist[i] = INF;
    }
    heap->push(vs, 0);
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
            if (G->matrix[u][i] + dis < dist[i]) {
                dist[i] = G->matrix[u][i] + dis;
                prev[i] = u;
                heap->push(i, dist[i]);
            }
        }
    }
}
