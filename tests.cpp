#include <iostream>

#include "heap.cpp"

using namespace std;

int main() {
    Heap heap;
    Heap heap2(5);
    Node node1 = {1, 1};
    Node node2 = {2, 2};
    Node node3 = {3, 3};
    Node node4 = {4, 4};
    Node node5 = {5, 5};
    Node node6 = {6, 6};
    Node node7 = {7, 7};
    Node node8 = {8, 8};
    heap.add(node1);
    heap.add(node4);
    heap.add(node2);
    heap.add(node3);
    heap.add(node5);
    heap.add(node6);
    heap.add(node7);
    heap.add(node8);
    cout << heap.get_min().key << " " << heap.get_min().value << endl;
    cout << heap << heap;
    Node node =  heap.extract_min();
    cout << heap;
    return 0;
}