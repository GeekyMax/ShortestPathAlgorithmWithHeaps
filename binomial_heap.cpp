//
// Created by h2279 on 2018/04/07.
//

#include "binomial_heap.h"

BinomialNode *binomial_node_make(int index, Type key) {
    BinomialNode *x = (BinomialNode *) malloc(sizeof(BinomialNode));
    if (x == NULL) {
        printf("memory allocation of node failed");
        exit(-1);
    }
    x->index = index;
    x->key = key;
    x->p = NULL;
    x->child = NULL;
    x->sibling = NULL;
    x->degree = 0;
    return x;
}

BiHeap binomial_heap_make() {
    BiHeap h = new _Binomialheap();
    if (h == NULL) {
        printf("the memory allocation of heap failed!\n");
        exit(-1);
    }
    h->head = NULL;
    return h;
}

BinomialNode *binomial_heap_top(BiHeap h) {
    BinomialNode *y = NULL;
    BinomialNode *x = h->head;
    if (x != NULL) {
        int min = x->key;
        y = x;
        x = x->sibling;
        while (x != NULL) {
            if (x->key < min) {
                min = x->key;
                y = x;
            }
            x = x->sibling;
        }
    }
    return y;
}

void binomial_link(BinomialNode *y, BinomialNode *z) {
    y->p = z;
    y->sibling = z->child;
    z->child = y;
    z->degree += 1;
}

BinomialNode *binomial_heap_merge(BiHeap h1, BiHeap h2) {
    BinomialNode *firstNode = NULL;
    BinomialNode *p = NULL;
    BinomialNode *p1 = h1->head;
    BinomialNode *p2 = h2->head;
    if (p1 == NULL || p2 == NULL) {
        if (p1 == NULL) {
            firstNode = p2;
        } else {
            firstNode = p1;
        }
        return firstNode;
    }

    if (p1->degree < p2->degree) {
        firstNode = p1;
        p = firstNode;
        p1 = p1->sibling;
    } else {
        firstNode = p2;
        p = firstNode;
        p2 = p2->sibling;
    }

    while (p1 != NULL && p2 != NULL) {
        if (p1->degree < p2->degree) {
            p->sibling = p1;
            p = p1;
            p1 = p1->sibling;
        } else {
            p->sibling = p2;
            p = p2;
            p2 = p2->sibling;
        }
    }
    if (p1 != NULL) {
        p->sibling = p1;
    } else {
        p->sibling = p2;
    }
    return firstNode;
}

BiHeap binomial_heap_union(BiHeap *h1, BiHeap *h2) {
    BiHeap h = binomial_heap_make();
    h->head = binomial_heap_merge(*h1, *h2);
    free(*h1);
    *h1 = NULL;
    free(*h2);
    *h2 = NULL;

    if (h->head == NULL) {
        return h;
    }

    BinomialNode *prev = NULL;
    BinomialNode *x = h->head;
    BinomialNode *next = x->sibling;

    while (next != NULL) {
        if (x->degree != next->degree
            || (next->sibling != NULL
                && x->degree == next->sibling->degree)) {
            // case 3 or case 2, just move forward
            prev = x;
            x = next;
        } else if (x->key <= next->key) {
            // x->key <= next->key
            x->sibling = next->sibling;
            binomial_link(next, x);
        } else {
            // x->key > next->key
            if (prev == NULL) {
                h->head = next;
            } else {
                prev->sibling = next;
            }
            binomial_link(x, next);
        }
        // change the next
        next = x->sibling;
    }
    return h;
}

void binomial_heap_insert_node(BiHeap *h, BinomialNode *x) {
    BiHeap h1 = binomial_heap_make();
    h1->head = x;
    *h = binomial_heap_union(h, &h1);
}

BinomialNode *binomial_heap_extract_min(BiHeap *h) {
    BinomialNode *p = (*h)->head;
    BinomialNode *x = NULL;
    BinomialNode *x_prev = NULL;
    BinomialNode *p_prev = NULL;
    Type min;

    if (p == NULL) {
        return p;
    }

    // find the root x with minimum key in the root list of h
    x = p;
    min = p->key;
    p_prev = p;
    p = p->sibling;
    while (p != NULL) {
        if (p->key < min) {
            x_prev = p_prev;
            x = p;
            min = p->key;
        }
        p_prev = p;
        p = p->sibling;
    }
    if (x == (*h)->head) {
        (*h)->head = x->sibling;
    } else if (x->sibling == NULL) {
        x_prev->sibling = NULL;
    } else {
        x_prev->sibling = x->sibling;
    }

    BinomialNode *child_x = x->child;
    if (child_x != NULL) {

        // generate a new Binomial Heap
        BiHeap h1 = binomial_heap_make();

        // reverse the order of linked list of x's children
        // and set the children's p to NULL
        // link h1->head to the head of resulting list
        child_x->p = NULL;
        h1->head = child_x;
        p = child_x->sibling;
        child_x->sibling = NULL;
        while (p != NULL) {
            p_prev = p;
            p = p->sibling;
            p_prev->sibling = h1->head;
            h1->head = p_prev;
            p_prev->p = NULL;
        }
        *h = binomial_heap_union(h, &h1);
    }

    return x;
}