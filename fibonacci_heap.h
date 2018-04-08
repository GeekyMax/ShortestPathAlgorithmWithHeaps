//
// Created by h2279 on 2018/04/03.
//

#ifndef SHORTESTPATHALGORITHMWITHHEAPS_FIBONACCI_HEAP_H
#define SHORTESTPATHALGORITHMWITHHEAPS_FIBONACCI_HEAP_H


#include <stdio.h>
#include <iostream>
#include "base.h"
#include <math.h>

using namespace std;

#if 0
#define LOG2(x) ({ \
        unsigned int _i = 0; \
        __asm__("bsr %1, %0" : "=r" (_i) : "r" ((x))); \
        _i; })
#else
#define LOG2(x) ((log((double)(x))) / (log(2.0)))
#endif
/**
 * the structure of fibonacci node
 */
typedef struct _FibonacciNode {
    pair<int, Type> element;
    Type key;                        // 关键字(键值)
    int degree;                        // 度数
    struct _FibonacciNode *left;    // 左兄弟
    struct _FibonacciNode *right;    // 右兄弟
    struct _FibonacciNode *child;    // 第一个孩子节点
    struct _FibonacciNode *parent;    // 父节点
    int marked;                       //是否被删除第1个孩子(1表示删除，0表示未删除)
} FibonacciNode, FibNode;
/**
 * the structure of the fibonacci heap
 * keyNum: the total number of nodes
 * maxDegree the max of the node's degree
 *
 */
typedef struct _FibonacciHeap {
    int keyNum;                    // 堆中节点的总数
    int maxDegree;                // 最大度
    struct _FibonacciNode *min;        // 最小节点(某个最小堆的根节点)
    struct _FibonacciNode **cons;    // 最大度的内存区域
} *FibHeap;

/**
 * make a new fibonacci node valuing key
 * @param key
 * @return
 */
static FibNode *fib_node_make(Type key);

/**
 * make an empty fibonacci heap
 * @return
 */
FibHeap fib_heap_make();

/**
 * insert a new node into a fibonacci heap
 * @param heap
 * @param node
 */
static void fib_heap_insert_node(FibHeap heap, FibNode *node);

/**
 * create a new node valuing index and key, then insert it into the heap
 * @param heap
 * @param index
 * @param key
 */
void fib_heap_insert_key(FibHeap heap, int index, Type key);

/**
 * extract the min node from the heap then return it
 * @param heap
 * @return the min node's pointer
 */
void fib_heap_extract_min(FibHeap heap);

/**
 * union two fibonacci heaps.
 * @param h1
 * @param h2
 * @return
 */
FibHeap fib_heap_union(FibHeap h1, FibHeap *h2);

#endif //SHORTESTPATHALGORITHMWITHHEAPS_FIBONACCI_HEAP_H
