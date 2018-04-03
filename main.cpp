#include "dijkstra.h"

int main() {
    priority_queue<node> Q;
    node node1 = node();
    node1.dis = 10;
    node1.u = 1;
    Q.push(node1);
    node node2 = node();
    node2.dis = 1;
    node2.u = 2;
    Q.push(node2);
    node node3 = node();
    node3.dis = 12;
    node3.u = 3;
    Q.push(node3);
    node node4 = node();
    node4.dis = 8;
    node4.u = 4;
    Q.push(node4);
    while (!Q.empty()) {
        int u = Q.top().u;
        int dis = Q.top().dis;
        Q.pop();
        printf("%d: %d\n", u, dis);
    }
    return 0;

}