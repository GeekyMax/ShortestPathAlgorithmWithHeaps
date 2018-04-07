//
// Created by h2279 on 2018/04/03.
//

#include "fibonacci_heap.h"

static void fib_node_remove(FibNode *node) {
    node->left->right = node->right;
    node->right->left = node->left;
}

static void fib_node_add(FibNode *node, FibNode *root) {
    node->left = root->left;
    root->left->right = node;
    node->right = root;
    root->left = node;
}

static void fib_node_cat(FibNode *a, FibNode *b) {
    FibNode *tmp;

    tmp = a->right;
    a->right = b->right;
    b->right->left = a;
    b->right = tmp;
    tmp->left = b;
}

FibHeap fib_heap_make() {
    FibHeap heap;

    heap = new _FibonacciHeap();
    if (heap == NULL) {
        printf("Error: make FibHeap failed\n");
        return NULL;
    }

    heap->keyNum = 0;
    heap->maxDegree = 0;
    heap->min = NULL;
    heap->cons = NULL;

    return heap;
}

static FibNode *fib_node_make(Type key) {
    FibNode *node;

    node = (FibNode *) malloc(sizeof(FibNode));
    if (node == NULL) {
        printf("Error: make BinomialNode failed\n");
        return NULL;
    }
    node->key = key;
    node->degree = 0;
    node->left = node;
    node->right = node;
    node->parent = NULL;
    node->child = NULL;

    return node;
}

static void fib_heap_insert_node(FibHeap heap, FibNode *node) {
    if (heap->keyNum == 0)
        heap->min = node;
    else {
        fib_node_add(node, heap->min);
        if (node->key < heap->min->key)
            heap->min = node;
    }
    heap->keyNum++;
}

void fib_heap_insert_key(FibHeap heap, int index, Type key) {
    FibNode *node;

    if (heap == NULL)
        return;

    node = fib_node_make(key);
    node->element = pair<int, Type>(index, key);
    if (node == NULL)
        return;
    fib_heap_insert_node(heap, node);
}

FibHeap fib_heap_union(FibHeap h1, FibHeap h2) {
    FibHeap tmp;

    if (h1 == NULL)
        return h2;
    if (h2 == NULL)
        return h1;

    // 以h1为"母"，将h2附加到h1上；下面是保证h1的度数大，尽可能的少操作。
    if (h2->maxDegree > h1->maxDegree) {
        tmp = h1;
        h1 = h2;
        h2 = tmp;
    }

    if ((h1->min) == NULL)                // h1无"最小节点"
    {
        h1->min = h2->min;
        h1->keyNum = h2->keyNum;
        free(h2->cons);
        free(h2);
    } else if ((h2->min) == NULL)           // h1有"最小节点" && h2无"最小节点"
    {
        free(h2->cons);
        free(h2);
    }                                   // h1有"最小节点" && h2有"最小节点"
    else {
        // 将"h2中根链表"添加到"h1"中
        fib_node_cat(h1->min, h2->min);
        if (h1->min->key > h2->min->key)
            h1->min = h2->min;
        h1->keyNum += h2->keyNum;
        free(h2->cons);
        free(h2);
    }

    return h1;
}

static FibNode *fib_heap_remove_min(FibHeap heap) {
    FibNode *min = heap->min;

    if (heap->min == min->right)
        heap->min = NULL;
    else {
        fib_node_remove(min);
        heap->min = min->right;
    }
    min->left = min->right = min;

    return min;
}

static void fib_heap_link(FibHeap heap, FibNode *node, FibNode *root) {
    // 将node从双链表中移除
    fib_node_remove(node);
    // 将node设为root的孩子
    if (root->child == NULL)
        root->child = node;
    else
        fib_node_add(node, root->child);

    node->parent = root;
    root->degree++;
    node->marked = 0;
}

static void fib_heap_cons_make(FibHeap heap) {
    int old = heap->maxDegree;

    // 计算log2(x)，"+1"意味着向上取整！
    // ex. log2(13) = 3，向上取整为3+1=4。
    heap->maxDegree = LOG2(heap->keyNum) + 1;

    // 如果原本空间不够，则再次分配内存
    if (old >= heap->maxDegree)
        return;

    // 因为度为heap->maxDegree可能被合并，所以要maxDegree+1
    heap->cons = (FibNode **) realloc(heap->cons,
                                      sizeof(FibHeap) * (heap->maxDegree + 1));
}

static void fib_heap_consolidate(FibHeap heap) {
    int i, d, D;
    FibNode *x, *y, *tmp;

    fib_heap_cons_make(heap);//开辟哈希所用空间
    D = heap->maxDegree + 1;

    for (i = 0; i < D; i++)
        heap->cons[i] = NULL;

    // 合并相同度的根节点，使每个度数的树唯一
    while (heap->min != NULL) {
        x = fib_heap_remove_min(heap);    // 取出堆中的最小树(最小节点所在的树)
        d = x->degree;                    // 获取最小树的度数
        // heap->cons[d] != NULL，意味着有两棵树(x和y)的"度数"相同。
        while (heap->cons[d] != NULL) {
            y = heap->cons[d];            // y是"与x的度数相同的树"
            if (x->key > y->key)        // 保证x的键值比y小
            {
                tmp = x;
                x = y;
                y = tmp;

            }
            fib_heap_link(heap, y, x);    // 将y链接到x中
            heap->cons[d] = NULL;
            d++;
        }
        heap->cons[d] = x;
    }
    heap->min = NULL;

    // 将heap->cons中的结点重新加到根表中
    for (i = 0; i < D; i++) {
        if (heap->cons[i] != NULL) {
            if (heap->min == NULL)
                heap->min = heap->cons[i];
            else {
                fib_node_add(heap->cons[i], heap->min);
                if ((heap->cons[i])->key < heap->min->key)
                    heap->min = heap->cons[i];
            }
        }
    }
}

FibNode *_fib_heap_extract_min(FibHeap heap) {
    if (heap == NULL || heap->min == NULL)
        return NULL;

    FibNode *child = NULL;
    FibNode *min = heap->min;
    // 将min每一个儿子(儿子和儿子的兄弟)都添加到"斐波那契堆的根链表"中
    while (min->child != NULL) {
        child = min->child;
        fib_node_remove(child);
        if (child->right == child)
            min->child = NULL;
        else
            min->child = child->right;

        fib_node_add(child, heap->min);
        child->parent = NULL;
    }

    // 将min从根链表中移除
    fib_node_remove(min);
    // 若min是堆中唯一节点，则设置堆的最小节点为NULL；
    // 否则，设置堆的最小节点为一个非空节点(min->right)，然后再进行调节。
    if (min->right == min)
        heap->min = NULL;
    else {
        heap->min = min->right;
        fib_heap_consolidate(heap);
    }
    heap->keyNum--;

    return min;
}

void fib_heap_extract_min(FibHeap heap) {
    FibNode *node;

    if (heap == NULL || heap->min == NULL)
        return;

    node = _fib_heap_extract_min(heap);
    if (node != NULL)
        free(node);
}

static void renew_degree(FibNode *parent, int degree) {
    parent->degree -= degree;
    if (parent->parent != NULL)
        renew_degree(parent->parent, degree);
}

static void fib_node_destroy(FibNode *node) {
    FibNode *start = node;

    if (node == NULL)
        return;

    do {
        fib_node_destroy(node->child);
        // 销毁node，并将node指向下一个
        node = node->right;
        free(node->left);
    } while (node != start);
}