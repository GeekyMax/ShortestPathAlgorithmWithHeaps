//
// Created by h2279 on 2018/04/03.
//

#ifndef SHORTESTPATHALGORITHMWITHHEAPS_PRIORITY_HEAP_H
#define SHORTESTPATHALGORITHMWITHHEAPS_PRIORITY_HEAP_H

#include "fibonacci_heap.h"
#include "Heap.h"

using namespace std;

class FibonacciHeap : public Heap {
private:
    FibHeap *fibHeap;
public:

    FibonacciHeap();

    void push(int index, Type key) override;

    void pop() override;

    pair<int, Type> top() override;

    bool empty() override;

    void clear() override;
};

#endif //SHORTESTPATHALGORITHMWITHHEAPS_PRIORITY_HEAP_H
