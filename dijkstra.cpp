//
// Created by h2279 on 2018/04/03.
//

#include "dijkstra.h"

Graph create_graph() {
    int length, start, end;
    Graph graph = Graph();
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            graph.matrix[i][j] = INFINITY;
        }
    }
    cin >> graph.vexnum >> graph.edgnum;
    for (int i = 0; i < graph.edgnum; i++) {
        cin >> length >> start >> end;
        graph.matrix[start][end] = min(graph.matrix[start][end], length);
        graph.matrix[end][start] = min(graph.matrix[end][start], length);
    }
    return graph;
}

void dijkstra(Graph G, int vs, int prev[], int dist[]) {
    bool flag[MAX];
    priority_queue<node> Q;
    for (int i = 0; i < G.vexnum; ++i) {
        flag[i] = false;
        prev[i] = 0;
        dist[i] = G.matrix[vs][i];
    }
    node temp_node = node();
    temp_node.u = vs;
    temp_node.dis = 0;
    Q.push(temp_node);
    while (!Q.empty()) {
        int u = Q.top().u;
        int dis = Q.top().dis;
        if (flag[u]) {
            continue;
        }
        dist[u] = dis;
        flag[u] = true;
        for (int i = 0; i < G.vexnum; i++) {
            if (G.matrix[u][i] + dis < dist[i]) {
                dist[i] = G.matrix[u][i] + dis;
                prev[i] = u;
                temp_node.u = i;
                temp_node.dis = dist[i];
                Q.push(temp_node);
            }
        }
    }
}
