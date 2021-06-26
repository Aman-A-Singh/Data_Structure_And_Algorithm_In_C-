#include <iostream>
#include "SingleLinkedList.h"
#include "string"
#include "Book.h"

int main()
{
    try {
        SingleLinkedList<Book> bookList;

        Book b1("Tawan", "Premchand", 1250);
        bookList.append(b1);
        Book b2("History Of India", "Nehru", 2250);
        bookList.append(b2);
        Book b3("Wings of fire", "APJ", 1000);
        bookList.append(b3);
        Book b4("My experiments with truth", "Mahatama", 3000);
        bookList.append(b4);
        std::cout << "********Before deletion********" << std::endl;
        bookList.print();
        bookList.remove(3);
        std::cout << "********After deletion********" << std::endl;
        bookList.print();
    }
    catch (std::out_of_range& e) {
        std::cout << e.what();
    }
    //   bookList.clear();
    //    bookList.print();
    return EXIT_SUCCESS;
}