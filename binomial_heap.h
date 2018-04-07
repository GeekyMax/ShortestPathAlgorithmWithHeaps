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

BinomialNode *binomial_node_make(int index, Type key);

BiHeap binomial_heap_make();

BinomialNode *binomial_heap_top(BiHeap h);

void binomial_heap_insert_node(BiHeap *h, BinomialNode *x);

BinomialNode *binomial_heap_extract_min(BiHeap *h);

BiHeap binomial_heap_union(BiHeap *h1, BiHeap *h2);

#endif //SHORTESTPATHALGORITHMWITHHEAPS_BINOMIAL_HEAP_H
