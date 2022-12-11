#pragma once
namespace myLib
{
    template <typename T>
    class Queue
    {
    private:
        T *queue;
        size_t capacity = 10;
        int start;
        int rear;
        void reset_queue();

    public:
        /*Creates a queue with specified capacity*/
        Queue(size_t capacity);

        /*Inserts an element in the Queue at it's rear*/
        void add(T element);

        /*Deletes an element from the front of the queue*/
        T remove();

        /*Returns a copy pf the element at the front of the queue*/
        T front();

        /*Check whether the queue is empty*/
        bool isEmpty();

        /*Check whether the Queue is Full*/
        bool isFull();
    };
}

#include"QueueImplementation.h"