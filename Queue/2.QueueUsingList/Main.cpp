#include<iostream>
#include "Queue.h"
#include <exception>
#include <stdexcept>

int main(){
    try{
        myLib::Queue<std::string> string_queue{5};
        string_queue.add("A");
        string_queue.add("B");
        string_queue.add("C");
        string_queue.add("D");
        string_queue.add("E");
        // string_queue.add("F");
        std::cout << string_queue.remove() << std::endl;
        std::cout << string_queue.remove() << std::endl;
        std::cout << string_queue.remove() << std::endl;
        std::cout << string_queue.remove() << std::endl;
        std::cout << string_queue.remove() << std::endl;
        // std::cout << string_queue.remove() << std::endl;
    }catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
}