//#include "class.h"
#include <cstddef>
#include <stdexcept>

template <typename T>
Vector<T>::Vector()
{
    logicalSize = 0;
    allocatedSize = INIT_ALLOC_SIZE;
    data = new T[allocatedSize];
}

template <typename T>
Vector<T>::Vector(size_t initSize)
{
    logicalSize = 0;
    allocatedSize = initSize;
    data = new T[allocatedSize];
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] data;
}

template <typename T>
bool Vector<T>::empty() const
{
    return !logicalSize;
}

template <typename T>
size_t Vector<T>::size() const
{
    return logicalSize;
}

template <typename T>
T &Vector<T>::at(size_t i)
{
    // Check bounds.
    if (i >= logicalSize)
    {
        throw std::out_of_range("Index out of range");
    }

    return data[i];
}

template <typename T>
T &Vector<T>::front()
{
    return at(0);
}

template <typename T>
T &Vector<T>::back()
{
    return at(logicalSize - 1);
}

template <typename T>
void Vector<T>::push_back(T elem)
{
    if (logicalSize == allocatedSize)
    {
        resize();
    }

    data[logicalSize] = elem;
    ++logicalSize;
}

template <typename T>
void Vector<T>::pop_back()
{
    if (logicalSize)
    {
        --logicalSize;
    }
}

template <typename T>
void Vector<T>::resize()
{
    allocatedSize *= 2;
    T *newData = new T[allocatedSize];
    for (size_t i = 0; i < logicalSize; ++i)
    {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}
