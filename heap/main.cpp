#include "heap.hpp"
#include <iostream>

int main() {
    heap<int> pq;
    pq.push(1);
    pq.push(3);
    pq.push(5);
    pq.push(7);
    pq.push(9);
    pq.push(2);
    pq.push(4);
    pq.push(6);
    pq.push(8);

    while (!pq.empty()) {
        int top = pq.peek();
        pq.pop();
        std::cout << top << std::endl;
    }
}
