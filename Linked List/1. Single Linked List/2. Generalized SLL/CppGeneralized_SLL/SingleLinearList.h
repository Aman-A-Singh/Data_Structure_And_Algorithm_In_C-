/* 
 * File:   SingleLinearList.h
 * Author: Aman Singh
 *
 * Created on 15 June 2021, 1:02 pm
 */

#ifndef SINGLELINEARLIST_H
#define SINGLELINEARLIST_H

#include <stdexcept>
#include <exception>
#include <ostream>
#include <iostream>

template <typename T>
class SingleLinearList {
public:
    SingleLinearList();
    SingleLinearList(const SingleLinearList& orig);
    virtual ~SingleLinearList();
    /*Create List if its empty or append node to the ned of the list*/
    void append(const T&);
    void print_list();
    bool isListEmpty();
    /* Delete all the nodes for the list */
    bool clear();
private:

    struct Node {
        T element;
        Node *next;
    };
    Node *start;
    size_t number_of_nodes;
};

template <typename T>
SingleLinearList<T>::SingleLinearList() {
    start = nullptr;
}

template <typename T>
SingleLinearList<T>::SingleLinearList(const SingleLinearList& orig) {
}

template <typename T>
SingleLinearList<T>::~SingleLinearList() {
    std::cout << "Destroying List" << std::endl;
    clear();
}

template <typename T>
void SingleLinearList<T>::append(const T& aRecord) {
    Node *new_node = nullptr;
    try {
        new_node = new Node{aRecord, nullptr};
    } catch (std::bad_alloc &error) {
        std::cerr << "Allocation of memory for the new node as failed!" << std::endl;
        std::cerr << error.what() << std::endl;
        std::cerr.flush();
        return;
    }
    if (isListEmpty()) {
        start = new_node;
    } else {
        Node* ptr = start;
        //traverse till the end of list
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        //insert new node to next of current last node
        ptr->next = new_node;
    }
    return;
}

template <typename T>
bool SingleLinearList<T>::clear() {
    //check if the list is empty
    if (!isListEmpty()) {
        Node *ptr = start;
        //traverse each node of list
        while (ptr != nullptr) {
            start = start->next;
            //delete the visited node
            delete (ptr);
            //make ptr point to next node
            ptr = start;
        }
        return true;
    }
    return false;
}

template <typename T>
bool SingleLinearList<T>::isListEmpty() {
    return start == nullptr;
}

template <typename T>
void SingleLinearList<T>::print_list() {
    //check if the list is empty
    if (isListEmpty()) {
        throw std::range_error("The list is empty");
    } else {
        Node* ptr = start;
        //traverse through the each node
        while (ptr != nullptr) {
            //print each node
            std::cout << ptr->element << std::endl;
            ptr = ptr->next;
        }
    }
}

#endif /* SINGLELINEARLIST_H */

