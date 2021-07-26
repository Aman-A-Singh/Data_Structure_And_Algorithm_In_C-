#include <iostream>
#include "SingleCircularLinkedList.h"
#include <string>
#include "Book.h"

void test_string();
void test_books();

int main()
{
	test_string();
	//test_books();
}

void test_string()
{
	SingleCircularLinkedList <std::string> string_SCLL;
	try {
		string_SCLL.append("A");
		string_SCLL.append("B");
		string_SCLL.append("C");
		string_SCLL.append("D");
		string_SCLL.print();
		string_SCLL.removeAt(4);
		std::cout << "*** After removing ***" << std::endl;
		string_SCLL.print();
		string_SCLL.clear();
	}
	catch(std::range_error &e) {
		std::cout << e.what();
	}
	catch (std::out_of_range& e) {
		std::cout << e.what();
	}
}

void test_books() {
	SingleCircularLinkedList <Book> bookSCLL;
	try {
		Book b1("Tawan", "Premchand", 1250);
		bookSCLL.append(b1);
		Book b2("History Of India", "Nehru", 2250);
		bookSCLL.append(b2);
		Book b3("Wings of fire", "APJ", 1000);
		bookSCLL.append(b3);
		Book b4("My experiments with truth", "Mahatama", 3000);
		bookSCLL.append(b4);
		Book b5("7 Habbits", "Colins", 3000);
		bookSCLL.append(b5);
		std::cout << "*** Book List ***" << std::endl;
		bookSCLL.print();
		bookSCLL.removeAt(2);
		std::cout << "*** After removing List ***" << std::endl;
		bookSCLL.print();

	}
	catch (std::range_error& e) {
		std::cout << e.what();
	}
	catch (std::out_of_range& e) {
		std::cout << e.what();
	}
}