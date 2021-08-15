#include <iostream>
#include "DoubleLinearLinkedList.h"
#include "Book.h"

void testString();
void testBook();

int main()
{
	//testString();
	testBook();
}

void testString() {
	DoubleLinearLinkedList::DoubleLinearLinkedList<std::string> dllString;
	try{
		dllString.append("aaa");
		dllString.append("bbb");
		dllString.append("ccc");
		dllString.append("ddd");
		dllString.append("eee");
		dllString.printForward();
		dllString.remove(5);
		dllString.printForward();
		dllString.resetList();
		dllString.printForward();

	}
	catch(std::range_error &err){
		std::cout << err.what() << std::endl;
	}
}

void testBook()
{

    DoubleLinearLinkedList::DoubleLinearLinkedList<Book>  bookList;
    try {
        Book b1("Tawan", "Premchand", 1250);
        bookList.append(b1);
        Book b2("History Of India", "Nehru", 2250);
        bookList.append(b2);
        Book b3("Wings of fire", "APJ", 1000);
        bookList.append(b3);
        Book b4("My experiments with truth", "Mahatama", 3000);
        bookList.append(b4);
        Book b5("7 Habbits", "Colins", 3000);
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
