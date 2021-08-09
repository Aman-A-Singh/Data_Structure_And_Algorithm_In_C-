#pragma once
#include <iostream>
#include <stdexcept>
#include <exception>
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
	//void printReverse();
	/*Returns true if the list is empty otherwise returns false*/
	bool isEmpty();
	///*Delete the Node from the List by Position*/
	//bool remove(size_t position);
	///*Delete the Node from the List by comparing the record*/
	//bool remove(T& record);
	///*Search for the record in the list. On success returns shared_ptr
	//Pointing to the book and on failure returns nullptr*/
	//auto search(T& record);
	/*Reset the List making it empty*/
	//void resetList();
};

template <typename T>
void DoubleLinearLinkedList<T>::append(const T& aRecord) {

	Node* newNode = new Node();
	// check whether allocation has failed
	if (newNode == NULL) {
		std::cerr << "\tInsufficient memory!!! new node cannot be created\n";
	}
	else {
		newNode->next = NULL;
		newNode->prev = NULL;
		newNode->data = aRecord;
	}
	if (isEmpty()) {
		head = newNode;
	}
	else {
		tail->next = newNode;
		newNode->prev = tail;
	}
	tail = newNode;
	number_of_nodes++;
}

template<typename T>
inline bool DoubleLinearLinkedList<T>::isEmpty()
{
	return head == NULL;
}

template<typename T>
inline void DoubleLinearLinkedList<T>::printForward()
{
	if (isEmpty()) {
		throw std::range_error("List is Empty");
	}
	else {
		Node* ptr = head;
		while (ptr != NULL) {
			std::cout << ptr->data << std::endl;
			ptr = ptr->next;
		}
	}
}