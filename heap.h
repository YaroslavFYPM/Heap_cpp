#pragma once

struct Node {
    int key;
    int value;
};

class Heap {
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
    int get_min();

    int get_capacity() const { return capacity; };
    int get_size() const { return size; };
    Node* get_data() const { return data; };

private:
    void sift_down(int parent);
    void sift_up(int child);

    int m_capacity;
    int m_size;
    Node* m_data;
};