//
// Created by h2279 on 2018/04/04.
//

#ifndef SHORTESTPATHALGORITHMWITHHEAPS_HEAP_H
#define SHORTESTPATHALGORITHMWITHHEAPS_HEAP_H

#include <iostream>

using namespace std;
typedef int Type;

/**
 * an abstract interface to find the minimum value
 * it provides five functions: push, pop, top,empty, clear
 * which are forced to be implements.
 */
class Heap {
public:
    virtual void push(int index, Type key) = 0;

    virtual void pop() = 0;

    virtual pair<int, Type> top()=0;

    virtual bool empty()=0;

    virtual void clear()=0;
};

#endif //SHORTESTPATHALGORITHMWITHHEAPS_HEAP_H
