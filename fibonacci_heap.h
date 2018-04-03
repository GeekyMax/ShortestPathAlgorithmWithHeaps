//
// Created by h2279 on 2018/04/03.
//

#ifndef SHORTESTPATHALGORITHMWITHHEAPS_FIBONACCI_HEAP_H
#define SHORTESTPATHALGORITHMWITHHEAPS_FIBONACCI_HEAP_H

#include <stdio.h>
#include <iostream>
using namespace std;
typedef int Type;

typedef struct _FibonacciNode {
    pair<int,Type> element;
    Type key;                        // 关键字(键值)
    int degree;                        // 度数
    struct _FibonacciNode *left;    // 左兄弟
    struct _FibonacciNode *right;    // 右兄弟
    struct _FibonacciNode *child;    // 第一个孩子节点
    struct _FibonacciNode *parent;    // 父节点
    int marked;                       //是否被删除第1个孩子(1表示删除，0表示未删除)
} FibonacciNode, FibNode;

typedef struct _FibonacciHeap {
    int keyNum;                    // 堆中节点的总数
    int maxDegree;                // 最大度
    struct _FibonacciNode *min;        // 最小节点(某个最小堆的根节点)
    struct _FibonacciNode **cons;    // 最大度的内存区域
} FibHeap;

// 创建Fibonacci堆
FibHeap *fib_heap_make();

// 新建键值为key的节点，并将其插入到斐波那契堆中
void fib_heap_insert_key(FibHeap *heap, Type key);
void fib_heap_insert_key(FibHeap *heap, int index, Type key);

// 移除最小节点
void fib_heap_extract_min(FibHeap *heap);

// 将h1, h2合并成一个堆，并返回合并后的堆
FibHeap *fib_heap_union(FibHeap *h1, FibHeap *h2);

// 销毁斐波那契堆
void fib_heap_destroy(FibHeap *heap);

// 打印"斐波那契堆"
void fib_print(FibHeap *heap);

Type top(FibHeap *heap);

#endif //SHORTESTPATHALGORITHMWITHHEAPS_FIBONACCI_HEAP_H
