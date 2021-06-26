#pragma once

#include "iostream"
#include "memory"
#include "stdexcept"

template <typename T>
class SingleLinkedList {
private:
	struct Node {
		T element;
		std::unique_ptr<Node> next;
		/*Default No-Arg Ctor for Node*/
		Node();
		/*Parameterized Ctor*/
		Node(const T& other);
		//Copy Ctor
		Node(const Node& other);
		/*Node Destructor*/
	};
	std::unique_ptr<Node> start;
	/*To maintain the node count*/
	size_t                number_of_nodes;

public:
	/*Default No-Arg Constructor*/
	SingleLinkedList();
	/*Destructor*/
	virtual ~SingleLinkedList();
	/*Append the Node to the List*/
	void append(const T&);
	/*Returns true if the list is empty else returns false*/
	bool isEmpty();
	/*Prints the Nodes from the List*/
	void print();
	/*Delete the Node from the List if the given position
	Returns true on success else throw std::range_error*/
	bool remove(size_t position);
	/*Delete the Node from the List by comparing the record*/
	bool remove(const T& record);
	/*Search for the record in the list. On success returns raw pointer
	Pointing to the record and on failure returns nullptr*/
	auto search(const T& record);
	/*Reset the List making it empty*/
	void resetList();

};

/*Default No-Arg Ctor for Node*/
template <typename T>
SingleLinkedList<T>::Node::Node() {
	next.reset();
}

/*Parameterized Ctor for Node*/
template<typename T>
SingleLinkedList<T>::Node::Node(const T& other) {
	element = other;
	next.reset();
}

template <typename T>
SingleLinkedList<T>::Node::Node(const Node& other) {
	element = other.element;
	next.reset();
}

/*Default no arg Constructor for Single Linked List*/
template <typename T>
SingleLinkedList<T>::SingleLinkedList() {
	start.reset();
	number_of_nodes = 0;
}

/*Destructor for List*/
template<typename T>
inline SingleLinkedList<T>::~SingleLinkedList()
{
	start.reset();
	number_of_nodes = 0;
}

template <typename T>
void SingleLinkedList<T>::append(const T& record) {
	/*node_ptr will point to Node which is to be inserted in the list*/
	std::unique_ptr<Node> node_ptr = std::make_unique<Node>(record);
	//check if the list is empty
	if (isEmpty()) {
		start = std::move(node_ptr);
	}
	else {
		Node* ptr = start.get();//getting a rw pointer out of unique pointer
		//traverse till the emd of loop
		while (ptr->next != nullptr) {
			ptr = ptr->next.get();
		}
		//transfer the owner ship of node_ptr to the next of last node in the list
		ptr->next = std::move(node_ptr);
	}
	//increase the node count
	number_of_nodes++;
}

template <typename T>
bool SingleLinkedList<T>::isEmpty() {
	return start == nullptr;
}

template<typename T>
void SingleLinkedList<T>::print()
{
	//check if the list is empty
	if (isEmpty()) {
		throw std::range_error("The List is Empty");
	}
	//get the raw pointer out of the (unique_ptr) start pointer on list
	Node* ptr = start.get();
	//Traverse each node in the list
	do {
		//print the each element of the node
		std::cout << ptr->element << std::endl;
		ptr = ptr->next.get();
	} while (ptr != nullptr);

}

template <typename T>
bool SingleLinkedList<T>::remove(size_t position) {
	//check if the list is empty
	if (isEmpty()) {
		throw std::range_error("The is is Empty");
		return false;
	}
	if (position > number_of_nodes) {
		throw std::out_of_range("The position is out of the List");
		return false;
	}

	Node* ptr = start.get();
	size_t counter{ 1 };
	if (position == 1) {
		/* Start now is the owner of the second node.
		Since the first node has no owner it's automatically deleted*/
		start = std::move(ptr->next);
		number_of_nodes--;
		return true;
	}
	else {
		while (position > counter) {
			ptr = ptr->next.get();
			counter++;
		}
		/*Ptr is currently at node number (position-1)
		 temp_ptr will node point to node to be deleted ie node at position
		 */
		Node* temp_ptr = ptr->next.get();
		/*next pointer of the node at (position-1) becomes the owner
		 of the node at (position+1)*/
		ptr->next = move(temp_ptr->next);
		number_of_nodes--;
	}
	return true;
}

template<typename T>
inline bool SingleLinkedList<T>::remove(const T& record)
{
	//check if the list is empty
	if (isEmpty()) {
		throw std::range_error("This List is Empty");
		return false;
	}
	Node* ptr = start.get();
	if (start->element == record) {
		/*Move the ownership of start->next pointer to the start pointer.
		The 1st node will have no owner. Hence it will get destroyed automatically*/
		start = std::move(ptr->next);
		number_of_nodes--;
		return true;
	}
	else {
		Node* temp = nullptr;
		//Traverse till the record is not found
		while (ptr->element != record) {
			temp = ptr; // follows ptr
			ptr = ptr->next.get();//will point to the record to be deleted
		}
		temp->next = std::move(ptr->next);
	}
	number_of_nodes--;
	return true;
}

template<typename T>
inline auto SingleLinkedList<T>::search(const T& record)
{
	//Check if list is empty
	if (isEmpty()) {
		throw std::range_error("This List is Empty");
	}
	else {
		Node* ptr = start.get();
		while (ptr->element != record) {
			ptr = ptr->next.get();
		}
		return ptr;
	}
	return nullptr;
}

template<typename T>
inline void SingleLinkedList<T>::resetList()
{
	start.reset();
	number_of_nodes = 0;
}
