//#include <cstdio>
#include "dijkstra.h"
#include "DefaultHeap.h"
#include "FibonacciHeap.h"
#include "BinomialHeap.h"

void dijkstra_test();

int main() {
    //    string path = "C:/Code/data.txt";
    dijkstra_test();
    return 0;

}

void dijkstra_test() {
    freopen("C:/Code/data.txt", "r", stdin);
    Graph G = create_graph();
    int dist[MAX];
    int prev[MAX];
    for (int i = 0; i < MAX; i++) {
        dist[i] = prev[i] = INFINITY;
    }
    Heap *heaps[3];
    heaps[0] = new FibonacciHeap();
    heaps[1] = new DefaultHeap();
    heaps[2] = new BinomialHeap();
    for (int index = 0; index < 3; index++) {
        cout << "-----------------------" << endl;
        cout << "heap index:" << index << endl;
        dijkstra(heaps[index], G, 0, prev, dist);
        for (int i = 0; i < G->vertex_num; ++i) {
            cout << i << ": prev:" << prev[i] << ", dist:" << dist[i] << endl;
        }
    }

}

//#include "FibonacciHeap.h"
//
//int main() {
//    FibonacciHeap Q = FibonacciHeap();
//    Q.push(1, 18);
//    Q.push(2, 13);
//    Q.push(3, 5);
//    Q.push(4, 15);
//    std::cout << Q.top().first << " " << Q.top().second << endl;
//    Q.pop();
//    Q.push(5, 20);
//    Q.push(6, 4);
//    std::cout << Q.top().first << " " << Q.top().second << endl;
//    Q.pop();
//    std::cout << Q.top().first << " " << Q.top().second << endl;
//    Q.pop();
//    std::cout << Q.top().first << " " << Q.top().second << endl;
//    Q.pop();
//    std::cout << Q.top().first << " " << Q.top().second << endl;
//    Q.pop();
//    std::cout << Q.top().first << " " << Q.top().second << endl;
//    Q.pop();
//    return 0;
//}