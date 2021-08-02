#include <iostream>
#include "SingleCircularLinkedList.h"

void test_string();
int main()
{
    test_string();
    return EXIT_SUCCESS;
}

void test_string() {
    SingleCircularLinkedList<std::string> scll_string;
    try {
        scll_string.append("aaa");
        scll_string.append("bbb");
        scll_string.append("ccc");
        scll_string.print();

    }
    catch (std::range_error& err) {
        std::cout << err.what() << std::endl;
    }
}