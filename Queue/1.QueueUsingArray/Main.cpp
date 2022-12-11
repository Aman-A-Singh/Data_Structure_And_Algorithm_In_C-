#include <iostream>
#include <exception>
#include "Queue.h"

int main(){
    try{
        myLib::Queue<std::string> stringQueue(5);
        stringQueue.add("A");
        stringQueue.add("B");
        stringQueue.add("C");
        stringQueue.add("D");
        stringQueue.add("E");

        std::cout << stringQueue.remove() << std::endl;
        std::cout << stringQueue.remove() << std::endl;
        std::cout << stringQueue.remove() << std::endl;
        std::cout << stringQueue.remove() << std::endl;
        std::cout << stringQueue.remove() << std::endl;
        std::cout << stringQueue.remove() << std::endl;
    }catch(std::out_of_range &e){
        std::cout << e.what() << std::endl;
    }
}