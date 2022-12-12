#pragma once
#include "Queue.h"
#include <exception>

namespace myLib
{
    template <typename T>
    Queue<T>::Queue(size_t capacity)
    {
        this->capacity = capacity;
    }

    template <typename T>
    void Queue<T>::add(T element)
    {
        if(isFull()){
            throw std::out_of_range("Queue OverFlow!!");
        }
        queue.push_back(element);
    }

    template <typename T>
    T Queue<T>::remove()
    {
        if(isEmpty()){
            throw std::out_of_range("Queue OverUnderlow!!");
        }
        return queue.pop_front();
    }

    template <typename T>
    bool Queue<T>::isEmpty()
    {
        return (queue.count_nodes()==0);
    }

    template <typename T>
    bool Queue<T>::isFull()
    {
        return (queue.count_nodes() == capacity);
    }

}