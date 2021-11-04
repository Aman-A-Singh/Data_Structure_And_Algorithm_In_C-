#pragma once
#include <memory>
#include <iostream>
#include <stdexcept>
#include <exception>
#include <sstream>
#include "DoubleLinearLinkedList.h"
/*Parameterized Ctor for Node*/
template<typename T>
DLL::DoubleLinearLinkedList<T>::Node::Node(const T & other) {
	this->element = other;
}

template<typename T>
void DLL::DoubleLinearLinkedList<T>::append(const T& record) {
	std::shared_ptr<Node> newNode = std::make_shared<Node>(record);

	if (isEmpty()) {
		head = newNode;//Make the newnode the first Node if the list is empty
	}
	else {
		tail->next = newNode;
		newNode->prev = tail;
	}
	//Tail always points to the last node (newNode)
	tail = newNode;
	number_of_nodes++;
}

template<typename T>
void DLL::DoubleLinearLinkedList<T>::printForward() {
	if (isEmpty()) {
		std::cout << "List is empty!" << std::endl;
	}
	else {
		Node* ptr = head.get();
		while (ptr) {
			std::cout << ptr->element << std::endl;
			ptr = ptr->next.get();
		}
	}
}

template<typename T>
void DLL::DoubleLinearLinkedList<T>::printReverse() {
	if (isEmpty()) {
		std::cout << "List is empty!" << std::endl;
	}
	else {
		std::shared_ptr<Node> ptr = tail;
		while (ptr) {
			std::cout << ptr->element << std::endl;
			ptr = ptr->prev.lock();
		}
	}
}

template<typename T>
bool DLL::DoubleLinearLinkedList<T>::isEmpty() {
	return  !(head && tail);

	//return number_of_nodes == 0;
}

template<typename T>
inline bool DLL::DoubleLinearLinkedList<T>::remove(size_t position)
{
	if (position > number_of_nodes) {
		std::ostringstream msg{ };
		msg << "The Position is out of range, the List containg only " << number_of_nodes << " nodes\n";
		throw std::out_of_range(msg.str());

	}

	/*If the node to be deleted is the first node*/
	if (position == 1) {
		/*if the list contains only one node*/
		if (head == tail) {
			/*head = nullptr;
			tail = nullptr;*/
			resetList();
		}
		else {
			/*Make second node in the list the first node*/
			head = head->next;
		}

	}
	else {
		/* Make pointer point to the first node */
		std::shared_ptr<Node> ptr = head;
		/*Traverse the pointer to the position of the node to be deleted*/
		for (size_t counter{ 1 }; counter < position; ++counter) {
			ptr = ptr->next;
		}
		if (ptr == tail) {
			/*Penultimate node is made the last node*/
			tail = tail->prev.lock();
			tail->next = nullptr;
		}
		else {
			/*Previous nodes next is made to point to next node of the node to be deleted*/
			(ptr->prev.lock())->next = ptr->next;
			/*The next nodes previous is made to point to the previous of the node to be deleted*/
			ptr->next->prev = ptr->prev;
		}
		ptr = nullptr;

	}
	return true;

}

template<typename T>
inline bool DLL::DoubleLinearLinkedList<T>::remove(T& record)
{
	if (isEmpty()) {
		throw std::out_of_range("The List is empty!");
	}
	// Executes if the list is not empty
	auto ptr = search(record);
	if (!ptr) { // if the record is not found
		return false;
	}

	if (head == tail) { //if the list contains only single record
		resetList();
	}
	else {
		//if the node to be deleted is the first node in the list
		if (head == ptr) {
			head = head->next; //make head point the the second node
			//reset second node's prev
			head->prev.reset();
		}
		else {
			//if the node to be deleted is the last node in the list
			if (tail == ptr) {
				//make tail point to the penultamate node
				tail = tail->prev.lock();
				//reset tail's next
				tail->next.reset();
			}
			else {
				//if the node to be deleted is a node in between
				(ptr->prev).lock()->next = ptr->next;
				ptr->next->prev = ptr->prev;

			}
		}
	}
	/*Not necessary : Since ptr is local shared pointer which will go out of scope */
	//ptr.reset();
	return true;

}

template<typename T>
inline auto DLL::DoubleLinearLinkedList<T>::search(T& record)
{
	std::shared_ptr<Node> ptr = nullptr;
	if (!isEmpty()) {

		ptr = head;
		while (ptr != nullptr) {
			if (ptr->element == record) {
				return ptr;
			}
			ptr = ptr->next;
		}

	}
	return ptr;
}

template<typename T>
inline void DLL::DoubleLinearLinkedList<T>::resetList()
{
	head.reset();
	tail.reset();
}


template<typename T>
inline bool DLL::DoubleLinearLinkedList<T>::better_remove(size_t position)
{
	if (position > number_of_nodes) {
		std::ostringstream msg{ };
		msg << "The Position is out of range, the List containg only " << number_of_nodes << " nodes\n";
		throw std::out_of_range(msg.str());

	}

	/*If the node to be deleted is the first node*/
	if (position == 1) {
		/*if the list contains only one node*/
		if (head == tail) {
			/*head = nullptr;
			tail = nullptr;*/
			resetList();
		}
		else {
			/*Make second node in the list the first node*/
			head = head->next;
		}

	}/*If the node to be deleted is the last node*/
	else if (position == number_of_nodes) {
		/*Penultimate node is made the last node*/
		tail = tail->prev.lock();
		tail->next = nullptr;
	}
	else {

		/*If the node to be deleted is closer to head*/
		if (position <= (number_of_nodes - position)) {
			/* Make pointer point to the first node */
			std::shared_ptr<Node> ptr = head;
			/*Traverse the pointer to the position of the node to be deleted*/
			for (size_t counter{ 1 }; counter < position; ++counter) {
				ptr = ptr->next;
			}
			/*Previous nodes next is made to point to next node of the node to be deleted*/
			(ptr->prev.lock())->next = ptr->next;
			/*The next nodes previous is made to point to the previous of the node to be deleted*/
			ptr->next->prev = ptr->prev;

			ptr = nullptr;
		}
		else {
			/*If the node to be deleted is closer to tail*/
			/* Make pointer point to the first node */
			std::shared_ptr<Node> ptr = tail;
			/*Traverse the pointer from tail to the position  of the node to be deleted*/
			for (size_t counter{ number_of_nodes }; counter > position; --counter) {
				ptr = ptr->prev.lock();
			}
			/*Previous nodes next is made to point to next node of the node to be deleted*/
			(ptr->prev.lock())->next = ptr->next;
			/*The next nodes previous is made to point to the previous of the node to be deleted*/
			ptr->next->prev = ptr->prev;

			ptr = nullptr;
		}
	}
	return true;

}