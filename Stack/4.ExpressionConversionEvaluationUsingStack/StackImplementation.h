#include "Stack.h"

namespace myLib
{
    template <typename T>
    Stack<T>::Stack(size_t capacity)
    {
        /* Resets the capacity if it is +ve nonzer value; otherwise sets to default size 5*/
        if (capacity > 0)
        {
            this->capacity = capacity;
        }
    }
    template <typename T>
    Stack<T>::Stack()
    {
        this->capacity = 5;
    }

    /*Add an element into the stack if the stack is not full.
     * throw over_flow exeception if the stack is full*/
    template <typename T>
    void Stack<T>::push(T element)
    {
        if (isFull())
        {
            throw std::overflow_error("Stack is Full!!");
        }
        stack.push_back(element);
    }

    /*Delete the topmost element from the stack provided the stack isnot empty
    Throw under_flow exception if the stack is empty*/
    template <typename T>
    T Stack<T>::pop()
    {
        if (isEmpty())
        {
            throw std::underflow_error("Stack Empty!!");
        }
        return stack.pop_back();
    }

    /*Return the copy of the topmost element if the stack is not empty
    Throws exception if the stack is empty*/
    template <typename T>
    T Stack<T>::peek()
    {
        if (isEmpty())
        {
            throw std::underflow_error("Stack Empty!!");
        }
        return stack.back();
    }

    /*Returns true if the stack is empty otherwise returns false*/
    template <typename T>
    bool Stack<T>::isEmpty()
    {
        if (stack.count_nodes() == 0)
        {
            return true;
        }
        return false;
    }

    /*Returns true if the stack is Full otherwise returns false*/
    template <typename T>
    bool Stack<T>::isFull()
    {
        if (stack.count_nodes() == capacity)
        {
            return true;
        }
        return false;
    }

}