#include <iostream>
#include "DoubleLinearLinkedList.h"

void testString();
int main()
{
	testString();
}

void testString() {
	DoubleLinearLinkedList<std::string> dllString;
	try{
		dllString.append("aaa");
		dllString.append("bbb");
		dllString.append("ccc");
		dllString.append("ddd");
		dllString.append("eee");
		dllString.printForward();

	}
	catch(std::range_error &err){
		std::cout << err.what() << std::endl;
	}
}