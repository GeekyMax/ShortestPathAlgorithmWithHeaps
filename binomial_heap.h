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
    struct  _BinomialNode *p;
    struct  _BinomialNode *child;
    struct  _BinomialNode *sibling;
} BinomialNode;

typedef struct _Binomialheap {
    BinomialNode *head;
} *BiHeap;

BinomialNode *generateNode(int index, Type key);
BinomialNode * binomialHeapMinimum(BiHeap h);
void binomialLink(BinomialNode * y, BinomialNode *z);
BinomialNode * binomialMerge(BiHeap h1, BiHeap h2);
BiHeap binomialHeapUnion(BiHeap *h1, BiHeap *h2);
BinomialNode * binomialHeapExtractMin(BiHeap *h);
BiHeap makeBinomialHeap();
void binomialHeapInsert(BiHeap *h, BinomialNode *x);

#endif //SHORTESTPATHALGORITHMWITHHEAPS_BINOMIAL_HEAP_H
