//
// Created by h2279 on 2018/04/03.
//

#include "FibonacciHeap.h"

/**
 * a default constructor to init the private fibonacci heap.
 */
FibonacciHeap::FibonacciHeap() {
    this->fibHeap = fib_heap_make();
}

/**
 * create a Pair<int,Type>, and create a node, and insert it into fibonacci heap
 * @param index
 * @param key
 */
void FibonacciHeap::push(int index, Type key) {
    fib_heap_insert_key(this->fibHeap, index, key);
}

/**
 * pop the root node,without return
 */
void FibonacciHeap::pop() {
    fib_heap_extract_min(this->fibHeap);
}

/**
 * return the top node's key and index. It will not pop the root node.
 * @return
 */
pair<int, Type> FibonacciHeap::top() {
    return this->fibHeap->min->element;
}

/**
 * check whether the heap is empty, if so, return true, else false
 * @return
 */
bool FibonacciHeap::empty() {
    return this->fibHeap->keyNum <= 0;
}

/**
 * clear all the data in the heap
 */
void FibonacciHeap::clear() {
    this->fibHeap = fib_heap_make();
}
