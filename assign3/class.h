#ifndef CLASS_H
#define CLASS_H

#include <cstddef>

template <typename T>
class Vector
{
public:
    Vector();
    Vector(size_t initSize);
    ~Vector();

    T &at(size_t i);
    T &front();
    T &back();

    void push_back(T elem);
    void pop_back();

    size_t size() const;
    bool empty() const;

private:
    const size_t INIT_ALLOC_SIZE = 8;
    size_t logicalSize;
    size_t allocatedSize;
    T *data;
    // Functions.
    void resize();
};

#include "class.cpp"
#endif