//
// Created by h2279 on 2018/04/03.
//

#ifndef SHORTESTPATHALGORITHMWITHHEAPS_PRIORITY_HEAP_H
#define SHORTESTPATHALGORITHMWITHHEAPS_PRIORITY_HEAP_H

#include "fibonacci_heap.h"
#include "Heap.h"

using namespace std;

/**
 * a class extends Heap which implements Push,Pop,Top,Empty,Clear functions
 * it use fibonacci heap data structure
 */
class FibonacciHeap : public Heap {
private:
//    private struct to store the element
    FibHeap fibHeap;
public:
    /**
     * default constructor
     */
    FibonacciHeap();


    /**
     * create a Pair<int,Type>, and create a node, and insert it into fibonacci heap
     * @param index
     * @param key
     */
    void push(int index, Type key) override;

    /**
     * pop the root node,without return
     */
    void pop() override;

    /**
     * return the top node's key and index. It will not pop the root node.
     * @return
     */
    pair<int, Type> top() override;

    /**
     * check whether the heap is empty, if so, return true, else false
     * @return
     */
    bool empty() override;

    /**
     * clear all the data in the heap
     */
    void clear() override;
};

#endif //SHORTESTPATHALGORITHMWITHHEAPS_PRIORITY_HEAP_H
