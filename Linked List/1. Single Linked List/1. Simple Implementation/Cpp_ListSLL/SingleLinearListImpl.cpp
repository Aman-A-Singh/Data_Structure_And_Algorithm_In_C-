/* 
 * File:   SingleLinearList.h
 * Author: Aman Singh
 *
 * Created on 23 May 2021, 6:34 pm
 */

#include <iostream>
#include <cstdlib>
#include <string>

#include "SingleLinearList.h"

NODE* createList_or_append(NODE* start) {
    NODE* ptr; //used for traversing the list
    NODE* newNode; //used for creating new node

    //allocate memory for new node
    newNode = new NODE();
    //check whether allocation has failed
    if (newNode == NULL) {
        std::cerr << "\tInsufficient memory!!! new node cannot be created\n";
    } else {
        //if allocation is successful accept data
        newNode->next = NULL;
        acceptNodeData(newNode);
        //check whether the list is empty
        if (isListEmpty(start)) {
            //make new node the first node
            start = newNode;
            return start;
        } else {
            //point ptr to the begining of the list
            ptr = start;
            //traverse to the end of the existing list
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            //add new node to the end of list
            ptr->next = newNode;
        }
    }
    // return lis pointer
    return start;
}

void displayList(NODE *ptr) {
    if (isListEmpty(ptr)) {
        std::cerr << "\tThe list is empty!!\n";
    } else {
        std::cout << "\n\t**** List of Students *****\n";
        std::cout << " \t\tRoll No.\t\t Name" << std::endl;

        while (ptr != NULL) {
            std::cout << "\t\t" << ptr->name << "\t\t " << ptr->roll << std::endl;
            ptr = ptr->next;
        }
    }
}

void acceptNodeData(NODE * ptr) {
    std::cout << "\tEnter Student Roll Number : ";
    std::cin >> ptr->roll;
    std::cout << "\tEnter Student Name : ";
    while (getchar() != 10); //clear input stream
    std::cin >> ptr->name;
    return;
}

bool isListEmpty(NODE * start) {
    return (start == NULL);
}

void insertNode(NODE * start, int rollNo) {
    NODE *ptr;
    NODE * newNode;
    //check if the list is empty
    if (isListEmpty(start)) {
        std::cerr << "\tThe list is empty!!\n";
        return;
    }
    //making ptr point to the first node
    ptr = start;
    //searching roll number till end of the list
    while (ptr != NULL && ptr->roll != rollNo) {
        ptr = ptr->next;
    }
    //if ptr is pointing to or reached last node
    if (ptr == NULL) {
        std::cerr << "\tRoll No " << rollNo << " is not found\n";
        std::cerr << "\tInsert operation aborted!\n";
    } else {
        //allocate memory for the new node
        newNode = new NODE();
        //check whether allocation has failed
        if (newNode == NULL) {
            std::cerr << "\tInsufficient memory!!! new node cannot be created\n";
        } else {
            newNode->next = NULL;
            //if node is successfully created accept data
            acceptNodeData(newNode);
            //insert the new node in the list
            newNode->next = ptr->next;
            ptr->next = newNode;
        }
    }
    return;
}

NODE* insertNodeByPosition(NODE *start, size_t position) {
    NODE *ptr;
    NODE *newNode;
    int counter = 1;
    //check if the list is empty
    if (isListEmpty(start)) {
        std::cerr << "\tThe list is empty!!\n";
        return NULL;
    }
    //allocating memory for new node
    newNode = new NODE();
    if (newNode == NULL) {
        std::cerr << "\tInsufficient memory!!! new node cannot be created\n";
    } else {
        newNode->next = NULL;
        //accept data is allocation is successful
        acceptNodeData(newNode);
        //if position is 1
        if (position == 1) {
            //new nodes next points to first node
            newNode->next = start;
            //local list pointer points to new node
            start = newNode;
        } else {
            ptr = start;
            //traverse ptr to desired position (before the position
            // where new node is to be inserted)or till the last node
            while (ptr->next != NULL && counter < (position - 1)) {
                ptr = ptr->next;
                counter++;
            }
            //if ptr is pointing to or reached last node
            if (ptr->next == NULL) {
                std::cout << "\tPosition out of the list !!!\n";
                std::cout << "\tInserting the node at last position\n";
            }
            newNode->next = ptr->next;
            ptr->next = newNode;
        }
    }
    return start;
}

NODE* deleteNodeByPosition(NODE *start, size_t position) {
    NODE *ptr;
    NODE *temp;
    int counter = 1;
    //check if the list is empty
    if (isListEmpty(start)) {
        std::cerr << "\tThe list is empty!!\n";
        return NULL;
    }
    //whether first node is to be deleted
    if (position == 1) {
        ptr = start;
        start = start->next;
        free(ptr);
        return start;
    } else {
        ptr = start;
        while (ptr != NULL && counter < position) {
            temp = ptr;
            ptr = ptr->next;
            counter++;
        }
        if (ptr == NULL) {
            std::cout << "\tPosition out of the list\n";
        } else {
            //For deletion of any node other than the 1st node
            temp->next = ptr->next;
        }
        free(ptr);
    }
    return start;
}

NODE* deleteNodeByName(NODE *start, std::string nameToBeDeleted) {
    NODE *ptr;
    NODE *temp; // To follow ptr
    //Check if the list is empty
    if (isListEmpty(start)) {
        std::cout << "\tList is empty" << std::endl;
        return NULL;
    }
    //making ptr point to first NODE
    ptr = start;
    //Traverse the list until the name to delete is not found
    //or until ptr does not go beyond the list
    while (ptr != NULL and (ptr->name != nameToBeDeleted)) {
        temp = ptr;
        ptr = ptr->next;
    }
    // ptr has traversed beyond the list
    if (ptr == NULL) {
        std::cout << "\tThe student " << nameToBeDeleted << " is not present in the list" << std::endl;
    } else {
        // if ptr is pointing to the first node
        if (ptr == start) {
            //make start point to second node
            start = ptr->next;
        } else {
            temp->next = ptr->next;
        }
        //delete node
        free(ptr);
        std::cout << nameToBeDeleted << "\n\t\'s Record has been deleted" << std::endl;
    }
    return start;
}

NODE* reverseList(NODE *ptr) {
    return NULL;
}

size_t countNodes(NODE*ptr) {
    return 0;
}

NODE* sort(NODE*ptr) {
    return NULL;
}

NODE* move(NODE* ptr, int position) {
    return NULL;
}
