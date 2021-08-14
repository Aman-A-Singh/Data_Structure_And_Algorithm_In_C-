#pragma once
#include <iostream>
#include <stdexcept>
#include <exception>

namespace DoubleLinearLinkedList {
	template <typename T>
	class DoubleLinearLinkedList {

	private:
		struct Node {
			T data;
			Node* next;
			Node* prev;
		};
		Node* head{};
		Node* tail{};
		size_t number_of_nodes{};
	public:
		/*Append the Node to the List*/
		void append(const T&);
		/*Prints the Nodes from the List in forward direction*/
		void printForward();
		///*Prints the Nodes from the List in reverse direction*/
		void printReverse();
		/*Returns true if the list is empty otherwise returns false*/
		bool isEmpty();
		/*Delete the Node from the List by Position*/
		bool remove(size_t position);
		/*Delete the Node from the List by comparing the record*/
		bool remove(T& record);
		/*Search for the record in the list. On success returns shared_ptr
		//Pointing to the book and on failure returns nullptr*/
		auto search(T& record);
		auto search(T&& record);
		/*Reset the List making it empty*/
		void resetList();
	};
}

#include "DoubleLineaarLinkedList_Imp.h"