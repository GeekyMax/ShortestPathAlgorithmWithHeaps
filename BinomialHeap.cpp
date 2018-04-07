//
// Created by h2279 on 2018/04/07.
//

#include "BinomialHeap.h"

/**
 * default constructor
 * init the binomial heap
 */
BinomialHeap::BinomialHeap() {
    biHeap = binomial_heap_make();
}

/**
 * create a Pair<int,Type>, and create a node, and insert it into fibonacci heap
 * @param index
 * @param key
 */
void BinomialHeap::push(int index, Type key) {
    // create a node first, then push it to the heap
    BinomialNode *node = binomial_node_make(index, key);
    binomial_heap_insert_node(&biHeap, node);
}

/**
 * pop the root node,without return
 */
void BinomialHeap::pop() {
    binomial_heap_extract_min(&biHeap);
}

/**
 * return the top node's key and index. It will not pop the root node.
 * @return
 */
pair<int, Type> BinomialHeap::top() {
    BinomialNode *node = binomial_heap_top(biHeap);
    return pair<int, Type>(node->index, node->key);
}

/**
 * check whether the heap is empty, if so, return true, else false
 * @return
 */
bool BinomialHeap::empty() {
    return biHeap->head == NULL;
}

/**
 * clear all the data in the heap
 */
void BinomialHeap::clear() {
    free(biHeap);
    biHeap = binomial_heap_make();
}
