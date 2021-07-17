#pragma once
#include "iostream"
template <typename T>
class SingleCircularLinkedList
{
private:
	struct Node {
		T element;
		Node* next;
	};
	Node* start;
	Node* last;
	size_t number_of_nodes;

public:
	/*Default no argument Constructor*/
	SingleCircularLinkedList();
	/*Destructor*/
	//virtual ~SingleCircularLinkedList();
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

template <typename T>
SingleCircularLinkedList<T>::SingleCircularLinkedList() {
	start = nullptr;
	last = nullptr;
	number_of_nodes = 0;
}

template <typename T>
void SingleCircularLinkedList<T>::append(const T& aRecord) {
	Node* newNode = nullptr;
	try {
		newNode = new Node{ aRecord,nullptr};
	}
	catch (std::bad_alloc& error) {
		std::cerr << "Allocation of memory for the new node as failed!" << std::endl;
		std::cerr << error.what() << std::endl;
		std::cerr.flush();
		return;
	}
	if (isEmpty()) {
		start = newNode;
	}
	else {
		last->next = newNode;
	}
	last = newNode;
	last->next = start;
	number_of_nodes++;
	return;
}

template <typename T>
void SingleCircularLinkedList<T>::print() {
	if (isEmpty()) {
		throw std::range_error("The List is Empty");
	}
	Node* ptr = start;
	do {
		std::cout << ptr->element << std::endl;
		ptr = ptr->next;
	} while (ptr != start);
	return;
}

template <typename T>
bool SingleCircularLinkedList<T>::isEmpty() {
	return start == nullptr;
}

template <typename T>
void SingleCircularLinkedList<T>::clear() {
	if (isEmpty()) {
		return;
	}
	else {
		Node* ptr = start;
		last->next = nullptr;
		while (ptr != nullptr){
			start = start->next;
			delete(ptr);
			ptr=start;
		}
		last = nullptr;
	}
}

template<typename T>
inline void SingleCircularLinkedList<T>::removeAt(size_t position)
{
	if (isEmpty()) {
		throw std::range_error("The List is Empty");
	}
	int count{ 1 };
	if (position > number_of_nodes) {
		throw std::out_of_range("The Position is out of list");
	}else if (position == 1) {
		start = start->next;
		last->next = start;
		number_of_nodes--;
		return;
	}
	else {
		Node* ptr{ start };
		Node* temp = nullptr;
		while (count < position) {
			temp = ptr;
			ptr = ptr->next;
			count++;
			if (position == number_of_nodes) {
				last = temp;
			}
		}
		temp->next = ptr->next;
		number_of_nodes--;
		return;
	}
}
