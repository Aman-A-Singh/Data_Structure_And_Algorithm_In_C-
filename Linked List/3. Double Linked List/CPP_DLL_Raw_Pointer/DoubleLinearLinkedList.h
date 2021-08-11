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
	void printReverse();
	/*Returns true if the list is empty otherwise returns false*/
	bool isEmpty();
	/*Delete the Node from the List by Position*/
	bool remove(size_t position);
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


template<typename T>
inline void DoubleLinearLinkedList<T>::printReverse()
{
	if (isEmpty()) {
		throw std::range_error("List is Empty");
	}
	else {
		Node* ptr = tail;
		while (ptr != NULL) {
			std::cout << ptr->data << std::endl;
			ptr = ptr->prev;
		}
	}
}

template<typename T>
inline bool DoubleLinearLinkedList<T>::remove(size_t position)
{
	if (isEmpty()) {
		throw std::range_error("List is Empty");
	}
	else if (position > number_of_nodes) {
		throw std::out_of_range("Position out of List");
	}
	else {
		//If the node to delete is first node
		if (position == 1) {
			Node* ptr = head;
			//2nd Node in the list becomes the head
			//make head point to the ssecond node
			head = head->next;
			head->prev = NULL;
			//release the memory of node deleted
			delete(ptr);
			number_of_nodes--;
			return true;
		}//if the node to delete is the last node
		else if (position == number_of_nodes) {
			Node* ptr = tail;
			tail = tail->prev;
			tail->next = NULL;
			delete(ptr);
			number_of_nodes--;
			return true;
		}
		else {
			Node* ptr = head;
			for (size_t count{ 1 };count < position;count++) {
				ptr = ptr->next;
			}
			/*ptr will point to the node which ic to be delete*/
			ptr->next->prev = ptr->prev;
			ptr->prev->next = ptr->next;
			delete(ptr);
			number_of_nodes--;
			return true;
		}
	}
	return false;
}