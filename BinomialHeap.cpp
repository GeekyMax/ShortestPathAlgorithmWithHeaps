//
// Created by h2279 on 2018/04/07.
//

#include "BinomialHeap.h"


BinomialHeap::BinomialHeap() {
    biHeap = makeBinomialHeap();
}

void BinomialHeap::push(int index, Type key) {
    BinomialNode *node = generateNode(index, key);
    binomialHeapInsert(&biHeap, node);
}

void BinomialHeap::pop() {
    binomialHeapExtractMin(&biHeap);
}

pair<int, Type> BinomialHeap::top() {
    BinomialNode *node = binomialHeapMinimum(biHeap);
    return pair<int, Type>(node->index, node->key);
}

bool BinomialHeap::empty() {
    return biHeap->head == NULL;
}

void BinomialHeap::clear() {
    free(biHeap);
    biHeap = makeBinomialHeap();
}
