//
// Created by h2279 on 2018/04/04.
//

#include "DefaultHeap.h"

DefaultHeap::DefaultHeap() {
    Q = priority_queue<Node>();
    temp_node = Node();
}

void DefaultHeap::push(int index, Type key) {
    temp_node.index = index;
    temp_node.key = key;
    Q.push(temp_node);
}

void DefaultHeap::pop() {
    Q.pop();
}

pair<int, Type> DefaultHeap::top() {
    temp_node = Q.top();
    return pair<int, Type>(temp_node.index, temp_node.key);
}

bool DefaultHeap::empty() {
    return Q.empty();
}

void DefaultHeap::clear() {
    Q = priority_queue<Node>();
}