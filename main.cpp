#include <iostream>
#include "MyPriorityQueue.h"


int main() {
    MyPriorityQueue<int> queue;
    queue.push(3);
    queue.push(8);
    queue.push(4);
    queue.push(5);
    queue.push(10);
    std::cout << queue.pop(1) << " - pop() res" << std::endl;
    std::cout << queue.peek(1) << " - peek() res" << std::endl;
    //std::cout << queue.get_size();

    std::cout << queue;
    return 0;
}
