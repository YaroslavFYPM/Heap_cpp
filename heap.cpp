#include "heap.h"
#include <stdlib.h>
#include <unistd.h>

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

Heap:Heap(const Heap& heap)
{
    m_data = new Node [heap.get_capacity()];
    m_capacity = heap.get_capacity();
    m_size = heap.get_size();
    for (int i = 0; i < m_size; ++i) {
        m_data[i] = heap.get_data()[i];    // Автоматически переопределён опаратор присваивания для Node. Нам он подходит,
    }                                       // так как мы сами не выделяем память для полей это структуры.
}
