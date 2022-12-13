#include <iostream>
#include <stdexcept>
#include "Deque.h"

int main()
{

    myLib::Deque<std::string> dque(5);
    try
    {

        std::string s1{"first"};
        dque.push_back(s1);
        std::string s2{"second"};
        dque.push_front(s2);
        s1 = "third";
        dque.push_back(s1);
        s2 = "fourth";
        dque.push_front(s2);

        /*
         fourth, second, first, third
        */

        std::cout << "front()    : " << dque.front() << std::endl;
        std::cout << "back()     : " << dque.back() << std::endl;
        std::cout << "pop_back() : " << dque.pop_back() << std::endl;
        std::cout << "pop_front(): " << dque.pop_front() << std::endl;
        std::cout << "front()    : " << dque.front() << std::endl;
    }
    catch (const std::out_of_range &oe)
    {
        std::cout << oe.what() << std::endl;
    }

    return EXIT_SUCCESS;
}
