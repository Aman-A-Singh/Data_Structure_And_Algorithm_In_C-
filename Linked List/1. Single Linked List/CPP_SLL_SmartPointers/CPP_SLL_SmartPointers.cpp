#include <iostream>
#include "SingleLinkedList.h"
#include "string"

int main()
{
    try {
        SingleLinkedList<std::string> SLL;
        SLL.append("A");
        SLL.append("B");
        SLL.append("C");
        SLL.append("D");
        SLL.append("E");
        SLL.append("F");
        SLL.print();

        SLL.remove(4);
        SLL.print();
        SLL.remove("B");
        SLL.print();

    }
    catch (std::out_of_range &e) {
        std::cout << e.what();
    }
    catch (std::range_error& e) {
        std::cout << e.what();
    }
}