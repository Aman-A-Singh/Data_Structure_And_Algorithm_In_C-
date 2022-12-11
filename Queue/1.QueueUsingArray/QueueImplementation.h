#pragma once
#include "Queue.h"
#include <exception>

namespace myLib
{
    template <typename T>
    Queue<T>::Queue(size_t capacity)
    {
        this->capacity = capacity;
        reset_queue();
        queue = new T[capacity];
    }

    template <typename T>
    void Queue<T>::reset_queue()
    {
        start = -1;
        rear = -1;
    }

    template <typename T>
    void Queue<T>::add(T element){
        if(isFull()){
            throw std::out_of_range("Queue is OverFlow!!");
        }
        queue[++rear] = element; 
    }

    template <typename T>
    T Queue<T>::remove(){
        if(isEmpty()){
            throw std::out_of_range("Queue is UnderFlow!!");
        }
        T element = queue[++start];
        if(rear==start){
            reset_queue();
        }
        return element;
    }

    template <typename T>
    bool Queue<T>::isEmpty()
    {
        return (rear == -1);
    }

    template <typename T>
    bool Queue<T>::isFull()
    {
        return rear == (capacity - 1);
    }

}