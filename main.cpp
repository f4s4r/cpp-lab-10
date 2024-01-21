#include <iostream>
#include "MyPriorityQueue.h"


int main() {
    MyPriorityQueue<int> queue;
    queue.push(3);
    queue.push(8);
    queue.push(4);
    queue.push(5);
    queue.push(10);
    //std::cout << queue.get_size();
    return 0;
}
