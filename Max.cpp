#include <iostream>

#include "priority_queue.h"

using namespace std;

int main(int argc, char const *argv[])
{
    priority_queue tree(10);
    tree.enqueue(1);
    tree.enqueue(2);
    tree.enqueue(3);
    tree.enqueue(4);
    tree.enqueue(5);
    tree.enqueue(6);
    tree.enqueue(0);
    cout << "El top es: " << tree.Peek() << endl;
    tree.dequeue(0);
    cout << "El top es: " << tree.Peek() << endl;
    cout << "Is Empty: " << tree.isEmpty() << endl;
    cout << "Size: " << tree.getSize() << endl;
    return 0;
}
