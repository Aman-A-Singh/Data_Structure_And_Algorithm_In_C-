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
	std::shared_ptr<Node> last;
	size_t number_of_nodes;

public:
	/*Append the node to the list*/
	void append(const T&);
	/*Prints the list*/
	void print();
	/*Returns true if the list is empty*/
	bool isEmpty();
	/*Clears the list*/
	void clear();
	/*removes the node at the given position*/
	void removeAt(size_t);
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
	last = node_ptr;
	number_of_nodes++;
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

template <typename T>
void SingleCircularLinkedList<T>::clear() {
	if (isEmpty()) {
		return;
	}
	else {
		head->next.reset();
		head.reset();
	}
}

template<typename T>
inline void SingleCircularLinkedList<T>::removeAt(size_t position)
{
	//check if the list is empty
	if (isEmpty()) {
		throw std::range_error("The List is Empty");
	}
	if (position > number_of_nodes) {
		throw std::out_of_range("The Position is out of list");
	}
	if (position == 1) {
		/* Start now is the owner of the second node.*/
		head = head->next;
		/*last->next will point to second node*/
		last->next = head;
		number_of_nodes--;
		return;
	}
	else {
		Node* ptr = head.get();
		size_t count{ 1 };
		while (position > (count + 1)) {
			ptr = ptr->next.get();
			count++;
		}
		/*Ptr is currently at node number (position-1)*/
		/*next pointer of the node at (position-1) becomes the owner
		 of the node at (position+1)*/
		ptr->next = ptr->next->next;
		if (position == number_of_nodes) {
			std::shared_ptr<Node> temp_last(ptr);
			last = temp_last;
			temp_last = nullptr;
		}
		number_of_nodes--;
		return;
	}
}