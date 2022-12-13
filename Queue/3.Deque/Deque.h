#pragma once
#include <iostream>
#include <stdexcept>
#include "DLL.h"

namespace myLib
{
    template <typename T>
    class Deque
    {
    private:
        /* the double linear linked list will be adapted as a deque*/
        DoubleLinearList<T> dque;
        /* Maximum Capacity of the Deque*/
        size_t capacity;

    public:
        /*Creates a Deque of specified capacity*/
        Deque(size_t capacity);

        /*Creates a Dequeu of default capacity*/
        Deque();

        /*Returns True if the deque is empty otherwise returns false*/
        bool isEmpty();

        /*Retursn true is the Deque is Full otherwise returns False*/
        bool isFull();

        /*Inserts the element at the front of the queue is the queue is not full;
          if the deque is full, insert operation throws overflow error
        */
        void push_front(T element);

        /*Deletes the element from the front of the queue is the queue is not empty;
          if the deque is empty, delete operation throws underflow error
        */
        T pop_front();

        /*Inserts the element at the rear of the queue is the queue is not full;
          if the deque is full, insert operation throws overflow error
        */
        void push_back(T element);

        /*Deletes the element from the rear of the queue is the queue is not empty;
         if the deque is empty, delete operation throws underflow error
         */
        T pop_back();

        /*Returns a copy of element at front without deleting it*/
        T front();

        /*Returns a copy of element at rear without deleting it*/
        T back();
    };
}

#include "DequeImplementation.h"