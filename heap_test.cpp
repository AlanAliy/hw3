#include "heap.h"
#include <string>
#include <functional>
#include <iostream>

void intHeapMinTest() {
    Heap<int> min_heap;

    min_heap.push(5);
    min_heap.push(8);
    min_heap.push(3);
    min_heap.push(1);
    min_heap.push(2);

    while(!min_heap.empty()) {
        std::cout << min_heap.top() << " ";
        min_heap.pop();
    }
    std::cout << std::endl;
}

void intHeapMaxTest() {

    Heap<int, std::greater<int>> max_heap(4);
    max_heap.push(5);
    max_heap.push(8);
    max_heap.push(3);
    max_heap.push(1);
    max_heap.push(2);

    while(!max_heap.empty()) {
        std::cout << max_heap.top() << " ";
        max_heap.pop();
    }
    std::cout << std::endl;

}

void stringMaxHeap() {
    Heap<std::string, std::greater<std::string>> max_heap(3);
    max_heap.push("alan");
    max_heap.push("zebra");
    max_heap.push("xray");
    max_heap.push("tango");
    max_heap.push("kilo");

    while(!max_heap.empty()) {
        std::cout << max_heap.top() << " ";
        max_heap.pop();
    }
    std::cout << std::endl;

}

int main() {
    
    intHeapMinTest();
    intHeapMaxTest();
    stringMaxHeap();
    
    return 0;
}