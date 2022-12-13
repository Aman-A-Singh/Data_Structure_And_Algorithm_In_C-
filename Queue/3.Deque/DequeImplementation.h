#include "Deque.h"

namespace myLib
{
    template <typename T>
    inline Deque<T>::Deque(size_t capacity)
    {
        this->capacity = capacity;
    }

    template <typename T>
    inline Deque<T>::Deque()
    {
        capacity = 10;
    }

    template <typename T>
    bool Deque<T>::isEmpty()
    {
        return dque.isEmpty();
    }

    template <typename T>
    bool Deque<T>::isFull()
    {
        return (dque.count_nodes() == capacity);
    }

    template <typename T>
    void Deque<T>::push_front(T element)
    {
        if (!isFull())
        {
            dque.push_front(element);
        }
        else
        {
            throw std::out_of_range("Deque Overflow");
        }
    }

    template <typename T>
    T Deque<T>::pop_front()
    {
        if (isEmpty())
        {
            throw std::out_of_range("Deque Underflow");
        }
        return dque.pop_front();
    }

    template <typename T>
    void Deque<T>::push_back(T element)
    {
        if (!isFull())
        {
            dque.push_back(element);
        }
        else
        {
            throw std::out_of_range("Deque Overflow");
        }
    }

    template <typename T>
    T Deque<T>::pop_back()
    {
        if (isEmpty())
        {
            throw std::out_of_range("Deque Underflow");
        }
        return dque.pop_back();
    }

    template <typename T>
    T Deque<T>::front(){
        if(isEmpty()){
            throw std::out_of_range("Deque Underflow");
        }
        return dque.front();
    }

    template <typename T>
    T Deque<T>::back(){
        if(isEmpty()){
            throw std::out_of_range("Deque Underflow");
        }
        return dque.back();
    }
}