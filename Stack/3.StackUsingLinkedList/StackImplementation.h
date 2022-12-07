#pragma once
#include "Stack.h"

namespace myLib
{
    template <typename T>
    Stack<T>::Stack(size_t capacity)
    {
        this->capacity = capacity;
    }

    template <typename T>
    bool Stack<T>::isEmpty()
    {
        if (!top)
        {
            return true;
        }
        return false;
    }

    template <typename T>
    void Stack<T>::push(T element)
    {
        std::unique_ptr<Node> nodeptr = std::make_unique<Node>(element);
        if (!isEmpty())
        {
            nodeptr->next = std::move(top);
        }
        top = std::move(nodeptr);
    }

    template <typename T>
    T Stack<T>::pop()
    {
        if (isEmpty())
        {
            throw std::out_of_range("Stack Underflow! Stack is Empty");
        }
        T element = top->data;
        top = std::move(top->next);
        return element;
    }

    template <typename T>
    T Stack<T>::peek(){
        if(isEmpty()){
            throw std::out_of_range("Stack UnderFlow! Stack is Empty");
        }
        return top->data;
    }


}