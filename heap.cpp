#include "heap.h"
#include <stdlib.h>
#include <unistd.h>

using namespace std;

Heap::Heap()
{
    m_data = new Node [HEAP_SIZE];
    m_capacity = HEAP_SIZE;
    m_size = 0;
}

Heap::Heap(int capacity)
{
    m_data = new Node [capacity];
    m_capacity = capacity;
    m_size = 0;
}

Heap::Heap(const Heap& heap)
{
    m_data = new Node [heap.get_capacity()];
    m_capacity = heap.get_capacity();
    m_size = heap.get_size();
    for (int i = 0; i < m_size; ++i) {
        m_data[i] = heap.get_data()[i];    // Автоматически переопределён опаратор присваивания для Node. Нам он подходит,
    }                                       // так как мы сами не выделяем память для полей это структуры.
}

Heap::~Heap()
{
    delete [] m_data;
    m_data = NULL;
}

void Heap::sift_down(int parent)
{
    if (parent > m_size) {
        cerr << "Invalid argument: parent = " << parent << endl;
        throw INVALID_ARGUMENT;
    }

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
        Node tmp = m_data[parent];
        m_data[parent] = m_data[least];
        m_data[least] = tmp;

        sift_down(least);
    }
}

void Heap::sift_up(int child)
{
    if (child > m_size) {
        cerr << "Invalid argument: child = " << child << endl;
        throw INVALID_ARGUMENT;
    }

    int parent;
    for (parent = (child - 1)/2; parent >= 0; child = parent, parent = (child - 1)/2) {

        if ( m_data[parent].key > m_data[child].key ) {
            Node tmp = m_data[parent];
            m_data[parent] = m_data[child];
            m_data[child] = tmp;
        } else
            break;

    }
}

void Heap::add(Node node)
{
    if (m_capacity == m_size) {
        cerr << "Heap is full" << endl;
        throw HEAP_OVERFLOW;
    }
    m_data[m_size] = node;
    ++m_size;
    sift_up(m_size-1);
}

Node Heap::get_min() const
{
    if (m_size < 1) {
        cerr << "Heap is empty" << endl;
        throw HEAP_EMPTY;
    }

    return m_data[0];
}

Node Heap::extract_min()
{
    if (m_size < 1) {
        cerr << "Heap is empty" << endl;
        throw HEAP_EMPTY;
    }

    Node min = m_data[0];
    m_data[0] = m_data[m_size-1];
    --m_size;

    sift_down(0);

    return min;
}

Heap Heap::operator=(const Heap& heap2)
{
    delete [] m_data;
    m_data = new Node [heap2.get_capacity()];
    m_capacity = heap2.get_capacity();
    m_size = heap2.get_size();
    for (int i = 0; i < m_size; ++i) 
        m_data[i] = heap2.get_data()[i];
    return *this;
}

ostream& operator<<(ostream& output, const Heap& heap)
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
