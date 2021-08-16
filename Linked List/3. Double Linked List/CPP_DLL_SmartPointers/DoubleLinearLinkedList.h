#pragma once
#include <iostream>
#include <memory>

namespace DoubleLinearLinkedList {

	template <typename T>
	class DoubleLinearLinkedList {
	private:
		class Node {
			T element;					//record to be stored in the list node
			std::unique_ptr<Node> next; // pointer to the next node
			std::weak_ptr<Node>   prev; // pointer to the previous node
			/*Parameterized Ctor*/
			Node(const T& other);
			//Copy Ctor
			Node(const Node& other) = default;
			/*Node Destructor*/
		};
		std::unique_ptr<Node> head;
		std::weak_ptr<Node>   tail;
		size_t number_of_nodes;

	public:
		/*Append the Node to the List*/
		void append(const T&);
		/*Prints the Nodes from the List in forward direction*/
		void printForward();
		/*Prints the Nodes from the List in reverse direction*/
		void printReverse();
		/*Returns true if the list is empty otherwise returns false*/
		bool isEmpty();
		/*Delete the Node from the List by Position*/
		bool remove(size_t position);
		/*Delete the Node from the List by comparing the record*/
		bool remove(T& record);
		/*Search for the record in the list. On success returns shared_ptr
		Pointing to the book and on failure returns nullptr*/
		auto search(T& record);
		/*Reset the List making it empty*/
		void resetList();
	};

}