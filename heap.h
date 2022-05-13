#pragma once

#include <iostream>

#define HEAP_SIZE 10

using namespace std;

template<typename T>
struct Node
{
    int key;
    T value;
};

template<typename T>
class Heap
{
public:

    using NodeType = Node<T>;

    enum heap_error {
	    HEAP_OVERFLOW = 1,
	    HEAP_EMPTY,
	    INVALID_ARGUMENT
    };

    Heap(int capacity);
    Heap();
    Heap(const Heap& heap);
    ~Heap();

    void add(NodeType node);
    NodeType extract_min();
    NodeType get_min() const;

    Heap operator=(const Heap& heap);

    template<typename U>
    friend ostream& operator<<(ostream& output, const Heap<U>& heap);

    int get_capacity() const { return m_capacity; };
    int get_size() const { return m_size; };
    NodeType* get_data() const { return m_data; };

private:
    void sift_down(int parent);
    void sift_up(int child);

    int m_capacity;
    int m_size;
    NodeType* m_data;
};