#pragma once

#include <iostream>

#define HEAP_SIZE 10

using namespace std;

struct Node
{
    int key;
    int value;
};

class Heap
{
public:
    enum heap_error {
	    HEAP_OVERFLOW = 1,
	    HEAP_EMPTY,
	    INVALID_ARGUMENT
    };

    Heap(int capacity);
    Heap();
    Heap(const Heap& heap);
    ~Heap();

    void add(Node node);
    Node extract_min();
    Node get_min() const;

    Heap operator=(const Heap& heap);
    friend ostream& operator<<(ostream& output, const Heap& heap);

    int get_capacity() const { return m_capacity; };
    int get_size() const { return m_size; };
    Node* get_data() const { return m_data; };

private:
    void sift_down(int parent);
    void sift_up(int child);

    int m_capacity;
    int m_size;
    Node* m_data;
};