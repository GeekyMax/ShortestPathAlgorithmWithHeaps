//
// Created by h2279 on 2018/04/03.
//

#include "dijkstra.h"

void add_edge(Graph graph, int start, int end, Type length) {
    adjacentNode node = new _adjacentNode();
    node->end = end;
    node->length = length;
    node->next = graph->head[start];
    graph->head[start] = node;
    adjacentNode node1 = new _adjacentNode();
    node1->end = start;
    node1->length = length;
    node1->next = graph->head[end];
    graph->head[end] = node1;
}

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
    for (int i = 0; i < MAX; ++i) {
        graph->head[i] = nullptr;
    }
//    read the numbers
    char c;
    cin >> graph->vertex_num >> graph->edge_num;
//    read each lines
    for (int i = 0; i < graph->edge_num; i++) {
        cin >> c >> start >> end >> length;
        add_edge(graph, start, end, length);
        if (i % 200 == 0) {
            cout << i << endl;
        }
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
    int count = 0;
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
    adjacentNode temp_adjacent_node = nullptr;
    while (!heap->empty()) {
        if (count % 100 == 0) {
            cout << count << endl;
        }
        count++;
        int this_node = heap->top().first;
        int dis = heap->top().second;
        heap->pop();
        if (flag[this_node]) {
            continue;
        }
        dist[this_node] = dis;
        flag[this_node] = true;
        int index;
        temp_adjacent_node = G->head[this_node];
        while (temp_adjacent_node != nullptr) {
            index = temp_adjacent_node->end;
            if (temp_adjacent_node->length + dis < dist[index]) {
                dist[index] = temp_adjacent_node->length + dis;
                prev[index] = this_node;
                heap->push(index, dist[index]);
            }
            temp_adjacent_node = temp_adjacent_node->next;
        }
    }
}
