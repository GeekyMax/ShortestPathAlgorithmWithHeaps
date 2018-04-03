//
// Created by h2279 on 2018/04/03.
//

#include "FibonacciHeap.h"

FibonacciHeap::FibonacciHeap() {
    this->fibHeap = fib_heap_make();
}

void FibonacciHeap::push(int index, Type key) {
    fib_heap_insert_key(this->fibHeap, index, key);
}

void FibonacciHeap::pop() {
    fib_heap_extract_min(this->fibHeap);
}

pair<int, Type> FibonacciHeap::top() {
    return this->fibHeap->min->element;
}

bool FibonacciHeap::empty() {
    return this->fibHeap->keyNum <= 0;
}