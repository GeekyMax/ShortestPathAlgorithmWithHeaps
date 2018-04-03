//
// Created by h2279 on 2018/04/03.
//

#include "dijkstra.h"

Graph create_graph() {
    int length, start, end;
    Graph graph = new _graph();
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            graph->matrix[i][j] = INFINITY;
        }
    }
    cin >> graph->vexnum >> graph->edgnum;
    for (int i = 0; i < graph->edgnum; i++) {
        cin >> length >> start >> end;
        graph->matrix[start][end] = min(graph->matrix[start][end], length);
        graph->matrix[end][start] = min(graph->matrix[end][start], length);
    }
    return graph;
}

void dijkstra(Graph G, int vs, int prev[], int dist[]) {
    bool flag[MAX];
    FibonacciHeap Q = FibonacciHeap();
    for (int i = 0; i < G->vexnum; ++i) {
        flag[i] = false;
        prev[i] = INFINITY;
        dist[i] = INFINITY;
    }
    Q.push(vs, 0);
    while (!Q.empty()) {
        int u = Q.top().first;
        int dis = Q.top().second;
        Q.pop();
        if (flag[u]) {
            continue;
        }
        dist[u] = dis;
        flag[u] = true;
        for (int i = 0; i < G->vexnum; i++) {
            if (G->matrix[u][i] + dis < dist[i]) {
                dist[i] = G->matrix[u][i] + dis;
                prev[i] = u;
                Q.push(i,dist[i]);
            }
        }
    }
}
