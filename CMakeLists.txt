cmake_minimum_required(VERSION 3.8)
project(ShortestPathAlgorithmWithHeaps)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp dijkstra.cpp dijkstra.h fibonacci_heap.cpp fibonacci_heap.h FibonacciHeap.cpp FibonacciHeap.h Heap.h DefaultHeap.cpp DefaultHeap.h binomial_heap.cpp binomial_heap.h base.h BinomialHeap.cpp BinomialHeap.h)
add_executable(ShortestPathAlgorithmWithHeaps ${SOURCE_FILES})