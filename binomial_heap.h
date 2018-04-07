//
// Created by h2279 on 2018/04/07.
//

#ifndef SHORTESTPATHALGORITHMWITHHEAPS_BINOMIAL_HEAP_H
#define SHORTESTPATHALGORITHMWITHHEAPS_BINOMIAL_HEAP_H

#include "base.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _BinomialNode {
    Type key;
    int index;
    int degree;
    struct _BinomialNode *p;
    struct _BinomialNode *child;
    struct _BinomialNode *sibling;
} BinomialNode;

typedef struct _Binomialheap {
    BinomialNode *head;
} *BiHeap;

/**
 * generate a node valuing key and index.
 * @param index
 * @param key
 * @return the result binomialNode
 */
BinomialNode *binomial_node_make(int index, Type key);

/**
 * generate an empty binomial heap
 * @return this BiHeap
 */
BiHeap binomial_heap_make();

/**
 * find the minimum key from the binomial heap,
 * and return the minimum node's pointer
 * @param h the goal Biheap
 * @return the result node
 */
BinomialNode *binomial_heap_top(BiHeap h);

/**
 * unite heaps h1 and h2, returning the resulting heap.
 * @param h1 heap 1
 * @param h2 heap 2
 * @return the new heap
 */
BiHeap binomial_heap_union(BiHeap *h1, BiHeap *h2);

/**
 * insert node into the binomial heap
 * @param h the goal binomial heap
 * @param x the node inserted
 */
void binomial_heap_insert_node(BiHeap *h, BinomialNode *x);

/**
 * extract minimum node from the heap
 * @param h the goal heap
 * @return the minimum node
 */
BinomialNode *binomial_heap_extract_min(BiHeap *h);

#endif //SHORTESTPATHALGORITHMWITHHEAPS_BINOMIAL_HEAP_H
