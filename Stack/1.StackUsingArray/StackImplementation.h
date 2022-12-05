#pragma once
#include "Stack.h"
#include <exception>

template <typename T>
myLib::Stack<T>::Stack(size_t capacity)
{
    this->capacity = capacity;
    this->stck = new T[capacity];
}

template <typename T>
myLib::Stack<T>::~Stack()
{
    delete[](stck);
    stck = nullptr;
}

/*Returns true is the stack is empty*/
template <typename T>
bool myLib::Stack<T>::isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    return false;
}

/*Returns true isf the stack is full*/
template <typename T>
bool myLib::Stack<T>::isFull()
{
    if (top + 1 == capacity)
    {
        return true;
    }
    return false;
}

/*Insert an element in the stack*/
template <typename T>
void myLib::Stack<T>::push(T element)
{
    if (isFull())
    {
        throw std::out_of_range("Stack Overflow");
    }
    stck[++top] = element;
    return;
}

/*Delete the topmost element from the stack*/
template <typename T>
T myLib::Stack<T>::pop()
{
    if (isEmpty())
    {
        throw std::out_of_range("Stack Underflow");
    }
    T element = stck[top--];
    return element;
}

/*Returns a copy of thetopmost element from the stack*/
template <typename T>
T myLib::Stack<T>::peek()
{
    if(isEmpty()){
        throw std::out_of_range("Stack Underflow");
    }
    return stck[top];
}