#pragma once
#include <memory.h>
#include <vector>

namespace myLib
{
    template <typename T>
    class Stack
    {
    private:
        /*Maximum number of elements in the stack*/
        size_t capacity{};
        /*vector treated as stack*/
        std::vector<T> stck{};

    public:
        /*Stack with default capacity 5 */
        Stack(size_t capacity = 5);
        ~Stack();
        Stack(Stack &) = default;
        /*Returns true is the stack is empty*/
        bool isEmpty();
        /*Returns true isf the stack is full*/
        bool isFull();
        /*Insert an element in the stack*/
        void push(T);
        /*Delete the topmost element from the stack*/
        T pop();
        /*Returns a copy of thetopmost element from the stack*/
        T peek();
    };
}