//
// Created by h2279 on 2018/04/03.
//

#ifndef SHORTESTPATHALGORITHMWITHHEAPS_PRIORITY_HEAP_H
#define SHORTESTPATHALGORITHMWITHHEAPS_PRIORITY_HEAP_H

#include "fibonacci_heap.h"
using namespace std;
class FibonacciHeap {
public:
    FibHeap *fibHeap;
public:
    FibonacciHeap();

    void push(int index, Type key);

    void pop();

    pair<int, Type> top();

    bool empty();
};
#endif //SHORTESTPATHALGORITHMWITHHEAPS_PRIORITY_HEAP_H
