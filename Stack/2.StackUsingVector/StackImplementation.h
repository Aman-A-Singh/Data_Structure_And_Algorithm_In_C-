#pragma once
#include "Stack.h"
#include <exception>
namespace myLib
{
    template <typename T>
    Stack<T>::Stack(size_t capacity)
    {
        /*Specifies the maximum capacity of the stack*/
        this->capacity = capacity;
        /*Create a stack of the specified size and initialize all elements*/
        // stk.reserve(this->capacity);
        stck.assign(this->capacity, T());
        stck.clear();
    }

    template <typename T>
    Stack<T>::~Stack()
    {
        stck.clear();
        stck.shrink_to_fit();
        capacity = 0;
    }

    template <typename T>
    bool Stack<T>::isEmpty()
    {
        if (stck.size() == 0)
        {
            return true;
        }
        return false;
    }

    /*Returns true if the stack is full*/
    template <typename T>
    bool Stack<T>::isFull()
    {
        if (stck.size() == capacity)
        {
            return true;
        }
        return false;
    }

    /*Insert an element in the stack*/
    template <typename T>
    void Stack<T>::push(T element)
    {
        if (isFull())
        {
            throw std::out_of_range("Stack Overflow");
        }
        stck.push_back(element);
        return;
    }

    /*Delete the topmost element from the stack*/
    template <typename T>
    T Stack<T>::pop()
    {
        if (isEmpty())
        {
            throw std::out_of_range("Stack Underflow");
        }
        /*Get the copy of the top element*/
        T element = stck.back();
        /*Delete the element from the top of the vector*/
        stck.pop_back();
        /*Return the copy of the deleted element*/
        return element;
    }

    /*Returns a copy of thetopmost element from the stack*/
    template <typename T>
    T Stack<T>::peek()
    {
        if(isEmpty()){
            throw std::out_of_range("Stack Underflow");
        }
        return stck.back();
    }
}