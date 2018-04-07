//
// Created by h2279 on 2018/04/07.
//

#ifndef SHORTESTPATHALGORITHMWITHHEAPS_BINOMIALHEAP_H
#define SHORTESTPATHALGORITHMWITHHEAPS_BINOMIALHEAP_H

#include "binomial_heap.h"
#include "Heap.h"
class BinomialHeap: public Heap{
private:
    BiHeap biHeap;
public:
    void push(int index, Type key) override;

    void pop() override;

    pair<int, Type> top() override;

    bool empty() override;

    void clear() override;

    BinomialHeap();

};


#endif //SHORTESTPATHALGORITHMWITHHEAPS_BINOMIALHEAP_H
