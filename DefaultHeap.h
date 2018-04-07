//
// Created by h2279 on 2018/04/04.
//

#ifndef SHORTESTPATHALGORITHMWITHHEAPS_DEFAULTHEAP_H
#define SHORTESTPATHALGORITHMWITHHEAPS_DEFAULTHEAP_H

#include "Heap.h"
#include "base.h"

using namespace std;
typedef struct node {
    int index, key;

    bool operator<(const node &a) const {
        return a.key < key;
    }//head重载 < ，以 key 从小到大排列
} DefaultNode;

class DefaultHeap : public Heap {
private:
    priority_queue<DefaultNode> Q;
    DefaultNode temp_node;
public:
    DefaultHeap();

    void push(int index, Type key) override;

    void pop() override;

    pair<int, Type> top() override;

    bool empty() override;

    void clear() override;
};

#endif //SHORTESTPATHALGORITHMWITHHEAPS_DEFAULTHEAP_H
