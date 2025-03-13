#include "stack.h"
#include <iostream>
#include <stdexcept>
#include <cassert>

void empty_test() {
    Stack<int> s;
    assert(s.empty());
    assert(s.size() == 0);

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(5);
    s.push(7);

    assert(s.size() == 5);
    assert(!s.empty());
}

void top_element_play() {
    Stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(5);
    s.push(7);

    assert(s.top() == 7);
    s.pop();
    assert(s.top() == 5);
}



void no_elements_test() {
    Stack<int> s;
    s.push(7);
    s.pop();

    assert(s.empty());

    try {
        s.pop();
    }
    catch(const std::underflow_error& error){
        std::cout << "Error thrown (pop), is empty" << std::endl;
    }

    try {
        s.top();
    }
    catch(const std::underflow_error& error){
        std::cout << "Error thrown (top), is empty" << std::endl;
    }
}

int main() {
    empty_test();
    std::cout << "empty test creation and push pass" << std::endl;

    top_element_play();
    std::cout << "top and pop work" << std::endl;

    no_elements_test();
    std::cout << "Empty stack works fine" << std::endl;

    return 0;
}