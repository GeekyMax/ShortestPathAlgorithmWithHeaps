//
// Created by h2279 on 2018/04/07.
//

#include "BinomialHeap.h"


BinomialHeap::BinomialHeap() {
    biHeap = binomial_heap_make();
}

void BinomialHeap::push(int index, Type key) {
    BinomialNode *node = binomial_node_make(index, key);
    binomial_heap_insert_node(&biHeap, node);
}

void BinomialHeap::pop() {
    binomial_heap_extract_min(&biHeap);
}

pair<int, Type> BinomialHeap::top() {
    BinomialNode *node = binomial_heap_top(biHeap);
    return pair<int, Type>(node->index, node->key);
}

bool BinomialHeap::empty() {
    return biHeap->head == NULL;
}

void BinomialHeap::clear() {
    free(biHeap);
    biHeap = binomial_heap_make();
}
