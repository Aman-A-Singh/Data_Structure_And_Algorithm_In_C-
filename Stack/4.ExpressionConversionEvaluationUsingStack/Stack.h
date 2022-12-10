#pragma once

#include <iostream>
#include "DLL.h"
#include <stdexcept>

namespace myLib
{
    template <typename T>
    class Stack
    {
    private:
        DoubleLinearList<T> stack;
        size_t capacity;

    public:
        /*Create a Stack with default size*/
        Stack(size_t capacity);
        Stack();
        
        /*Add an element into the stack if the stack is not full.
         * throw over_flow exeception if the stack is full*/
        void push(T element);

        /*Delete the topmost element from the stack provided the stack isnot empty
        Throw under_flow exception if the stack is empty*/
        T pop();

        /*Return the copy of the topmost element if the stack is not empty
        Throws exception if the stack is empty*/
        T peek();

        /*Returns true if the stack is empty otherwise returns false*/
        bool isEmpty();

        /*Returns true if the stack is Full otherwise returns false*/
        bool isFull();
    };
}
