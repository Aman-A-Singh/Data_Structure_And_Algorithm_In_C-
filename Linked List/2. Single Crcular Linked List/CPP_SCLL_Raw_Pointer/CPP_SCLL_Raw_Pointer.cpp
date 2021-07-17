#include <iostream>
#include "SingleCircularLinkedList.h"
#include <string>

void test_string();
int main()
{
	test_string();
}

void test_string()
{
	try {
		SingleCircularLinkedList <std::string> string_SCLL;
		string_SCLL.append("A");
		string_SCLL.append("B");
		string_SCLL.append("C");
		string_SCLL.append("D");
		string_SCLL.print();
		string_SCLL.removeAt(1);
		string_SCLL.print();
		string_SCLL.clear();
	}
	catch(std::range_error &e) {
		std::cout << e.what();
	}
}
