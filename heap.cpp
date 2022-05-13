#include "heap.h"

using namespace std;

template <typename T>
Heap<T>::Heap()
{
    m_data = new NodeType [HEAP_SIZE];
    m_capacity = HEAP_SIZE;
    m_size = 0;
}

template <typename T>
Heap<T>::Heap(int capacity)
{
    if (capacity < 1) {
        cerr << "Invalid argument: " << capacity << endl;
        throw INVALID_ARGUMENT;
    }

    m_data = new NodeType [capacity];
    m_capacity = capacity;
    m_size = 0;
}

template <typename T>
Heap<T>::Heap(const Heap& heap)
{
    m_data = new NodeType [heap.get_capacity()];
    m_capacity = heap.get_capacity();
    m_size = heap.get_size();

    for (int i = 0; i < m_size; ++i)
        m_data[i] = heap.get_data()[i];
}

template <typename T>
Heap<T>::~Heap()
{
    delete [] m_data;
    m_data = NULL;
}

template <typename T>
void Heap<T>::sift_down(int parent)
{
    
    int left = (1 + parent)*2 - 1;
    int right = (1 + parent)*2;
    int least = parent;

    if (left < m_size && ((m_data[left].key) < (m_data[parent].key)))
        least = left;
    else
        least = parent;

    if (right < m_size && ((m_data[right].key) < (m_data[least].key)))
        least = right;

    if (least != parent) {
        NodeType tmp = m_data[parent];
        m_data[parent] = m_data[least];
        m_data[least] = tmp;

        sift_down(least);
    }
}

template <typename T>
void Heap<T>::sift_up(int child)
{
    int parent;
    for (parent = (child - 1)/2; parent >= 0; child = parent, parent = (child - 1)/2) {

        if ( m_data[parent].key > m_data[child].key ) {
            NodeType tmp = m_data[parent];
            m_data[parent] = m_data[child];
            m_data[child] = tmp;
        } else
            break;
    }
}

template <typename T>
void Heap<T>::add(NodeType node)
{
    if (m_capacity == m_size) {
        cerr << "Heap is full" << endl;
        throw HEAP_OVERFLOW;
    }

    m_data[m_size] = node;
    ++m_size;

    sift_up(m_size-1);
}

template <typename T>
Node<T> Heap<T>::get_min() const
{
    if (m_size < 1) {
        cerr << "Heap is empty" << endl;
        throw HEAP_EMPTY;
    }

    return m_data[0];
}

template <typename T>
Node<T> Heap<T>::extract_min()
{
    if (m_size < 1) {
        cerr << "Heap is empty" << endl;
        throw HEAP_EMPTY;
    }

    NodeType min = m_data[0];
    m_data[0] = m_data[m_size-1];
    --m_size;

    sift_down(0);

    return min;
}

template <typename T>
Heap<T> Heap<T>::operator=(const Heap<T>& heap2)
{
    delete [] m_data;

    m_data = new NodeType [heap2.get_capacity()];
    m_capacity = heap2.get_capacity();
    m_size = heap2.get_size();

    for (int i = 0; i < m_size; ++i) 
        m_data[i] = heap2.get_data()[i];

    return *this;
}

template <typename T>
ostream& operator<<(ostream& output, const Heap<T>& heap)
{ 
    output << "Heap: capacity " << heap.get_capacity();
    output << ", current size " << heap.get_size() << endl;

    output << "data: " << (void*)heap.get_data() << endl;

    int i = 1;
    int j = 1;
    while (i < heap.get_size() + 1) {

        while ((i < j*2) && (i < heap.get_size() + 1)) {
            output << "(" << heap.get_data()[i-1].key << ", " << heap.get_data()[i-1].value << ") ";
            ++i;
        }

        j *= 2;
        cout << endl;
    }

    return output;
}


/*
int main() {
    Heap<string> h1;
    Heap<string> heap(5);
    Node<string> node1 = {3, "rrmr"};
    Node<string> node2 = {2, "abab"};
    Node<string> node3 = {5, "aaaa"};
    heap.add(node1);
    heap.add(node2);
    heap.add(node3);
    cout << heap;
    h1 = heap;
    cout << h1;
    cout << heap.get_min().value << endl;
    cout << heap.extract_min().value << endl;
    cout << heap.extract_min().value << endl;
    return 0;
}
*/

