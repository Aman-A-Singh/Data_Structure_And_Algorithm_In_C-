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
	//check if the list is empty
	if (isEmpty()) {
		throw std::range_error("The List is Empty");
	}
	if (position > number_of_nodes) {
		throw std::out_of_range("The Position is out of list");
	}
	Node* ptr{ start };
	size_t count{ 1 };
	if (position == 1) {
		/* Start now is the owner of the second node.*/
		start = ptr->next;
		/*last->next will point to second node*/
		last->next = start;
		number_of_nodes--;
		return;
	}
	else {
		while (position > (count+1)) {
			ptr = ptr->next;
			count++;
		}
		/*Ptr is currently at node number (position-1)
		 temp_ptr will point to node to be deleted ie node at position
		 */
		Node* temp_ptr = ptr->next;
		/*next pointer of the node at (position-1) becomes the owner
		 of the node at (position+1)*/
		ptr->next = temp_ptr->next;
		if (position == number_of_nodes) {
			last = ptr;
		}
		number_of_nodes--;
		return;
	}
}
