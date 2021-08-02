#pragma once
#include "iostream"
#include "memory"
#include "stdexcept"
template <typename T>
class SingleCircularLinkedList {
private:
	struct Node {
		T data;
		std::shared_ptr<Node> next;
		Node(const T&);
	};
	std::shared_ptr<Node> head;

public:
	/*Append the node to the list*/
	void append(const T&);
	/*Prints the list*/
	void print();
	/*Returns true if the list is empty*/
	bool isEmpty();
	/*Clears the list*/
	//void clear();
	/*removes the node at the given position*/
	//void removeAt(size_t);
};

template<typename T>
SingleCircularLinkedList<T>::Node::Node(const T& other) {
	data = other;
}

template <typename T>
bool SingleCircularLinkedList<T>::isEmpty() {
	return !head;
}

template <typename T>
void SingleCircularLinkedList<T>::append(const T& aRecord) {
	std::shared_ptr<Node> node_ptr = std::make_shared<Node>(aRecord);
	//check if the list is empty;
	if (isEmpty()) {
		head = node_ptr;
	}
	else {
		Node* ptr = head.get();
		while (ptr->next != head) {
			ptr = ptr->next.get();
		}
		ptr->next = node_ptr;
	}
	node_ptr->next = head;
	return;
}

template <typename T>
void SingleCircularLinkedList<T>::print() {
	if (isEmpty()) {
		throw std::range_error("The List is Empty");
	}
	else {
		Node* ptr = head.get();
		do {
			std::cout << ptr->data << std::endl;
			ptr = ptr->next.get();
		} while (ptr != head.get());
	}
}