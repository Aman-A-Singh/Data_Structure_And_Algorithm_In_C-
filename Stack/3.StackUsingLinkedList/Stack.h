#pragma once
#include <memory>
#include <vector>

namespace myLib
{

    template <typename T>
    class Stack
    {
    private:
        struct Node
        {
            T data;
            std::unique_ptr<Node> next;

            Node(T data)
            {
                this->data = data;
                next = nullptr;
            }
        };

        /*Maximum number of elements in the stack*/
        size_t capacity{};
        /*vector treated as stack*/
        std::unique_ptr<Node> top;

    public:
        /*Stack with default capacity 5 */
        Stack(size_t capacity = 5);
        //~Stack();
        Stack(Stack &) = default;
        /*Returns true is the stack is empty*/
        bool isEmpty();
        /*Returns true isf the stack is full*/
        // bool isFull();
        /*Insert an element in the stack*/
        void push(T);
        /*Delete the topmost element from the stack*/
        T pop();
        /*Returns a copy of thetopmost element from the stack*/
        T peek();
    };
}