#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include "DoubleLinearLinkedList.h"
#include "Book.h"

void testString();
void testBooks();
int main()
{
    //testString();
    testBooks();
}

void testString() {
    DLL::DoubleLinearLinkedList<std::string> DLL_string;
    try {
        DLL_string.append("AAA");
        DLL_string.append("BBB");
        DLL_string.append("CCC");
        DLL_string.append("DDD");
        /*DLL_string.printForward();
        DLL_string.printReverse();*/
        //DLL_string.remove(2);
        DLL_string.better_remove(3);
        DLL_string.printForward();
    }
    catch (std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    }
}

void testBooks() {
    DLL::DoubleLinearLinkedList<mylib::Book>  bookList;
    try {
        mylib::Book b1("Tawan", "Premchand", 1250);
        bookList.append(b1);
        mylib::Book b2("History Of India", "Nehru", 2250);
        bookList.append(b2);
        mylib::Book b3("Wings of fire", "APJ", 1000);
        bookList.append(b3);
        mylib::Book b4("My experiments with truth", "Mahatama", 3000);
        bookList.append(b4);
        mylib::Book b5("7 Habbits", "Colins", 3000);
        bookList.append(b5);
        std::cout << "***Forward direction ***" << std::endl;
        bookList.printForward();
        bookList.remove(b3);
        std::cout << "After Deletion :\n";
        bookList.printForward();
        /*std::cout << "***Backward direction ***" << std::endl;
        bookList.printReverse();
        bool hasDeleted = bookList.remove(1);
        std::cout << "is the book deleted ?" << std::boolalpha << hasDeleted <<std::endl;
        std::cout << "***REst of the Books***" << std::endl;
        std::cout << "***Forward direction ***" << std::endl;
        bookList.printForward();
        std::cout << "***Backward direction ***" << std::endl;
        bookList.printReverse();*/
        std::cout << "Done!";
    }
    catch (std::out_of_range& err) {
        std::cerr << err.what() << std::endl;
    }
}