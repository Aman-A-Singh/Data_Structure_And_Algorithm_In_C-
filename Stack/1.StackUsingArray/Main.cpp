#include <iostream>
#include <stdexcept>
#include "Stack.h"
// #include "StackImplementation.h"
#include <vector>

int main()
{
    myLib::Stack<int> intStack(6);
    try
    {
        //	std::cout << "Peek : " << intStack.peek() << std::endl;
        intStack.push(10);
        intStack.push(20);
        intStack.push(30);
        intStack.push(40);
        intStack.push(50);
        intStack.push(60);
        std::cout << "Peek : " << intStack.peek() << std::endl;

        std::cout << intStack.pop() << std::endl;
        std::cout << intStack.pop() << std::endl;
        std::cout << intStack.pop() << std::endl;
        std::cout << intStack.pop() << std::endl;
        std::cout << intStack.pop() << std::endl;
        std::cout << intStack.pop() << std::endl;
        std::cout << intStack.pop() << std::endl;
    }
    catch (std::out_of_range &err)
    {
        std::cerr << err.what() << std::endl;
    }
    std::cout << "The End!\n";
    return 0;
}