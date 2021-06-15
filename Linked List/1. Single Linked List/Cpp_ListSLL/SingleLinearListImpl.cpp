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
        std::cout <<"\t" << nameToBeDeleted << "\'s Record has been deleted" << std::endl;
    }
    return start;
}

NODE* reverseList(NODE *start) {
    NODE *ptr = NULL;
    NODE *temp = NULL;
    NODE *ptr1 = NULL;
    // check if the list contains some node
    if (isListEmpty(start)) { // if list is not empty
        std::cout << "\tThe list is empty\n";
    } else {
        ptr = start; // make ptr point to first node
        temp = ptr->next; //make temp point to second node
        ptr->next = NULL; //make 1st node as last node
        while (temp != NULL) {
            ptr1 = temp->next;
            temp->next = ptr;
            ptr = temp;
            temp = ptr1;
        }
        start = ptr;
    }
    return start;
}

size_t countNodes(NODE* ptr) {
    size_t count = 0;
    // check if the list contains some node
    if (isListEmpty(ptr)) { // if list is not empty
        std::cout << "\tThe list is empty\n";
    } else {
        while (ptr != NULL) {
            count++;
            ptr = ptr->next;
        }
    }
    return count;
}

NODE* sort(NODE*start) {
    NODE *ptr1;
    NODE *temp1;
    NODE *ptr2;
    NODE *temp2;
    size_t i;
    size_t j;
    size_t no_nodes;

    if (isListEmpty(start)) {
        std::cout << "\tThe list is empty\n";
    } else {
        //count number of nodes in the list
        no_nodes = countNodes(start);

        for (i = 2; i <= no_nodes; ++i) {
            //Move ptr1 to ith node
            ptr1 = move(start, i);
            //Move temp1 to (i-1)th node
            temp1 = move(start, i - 1);
            //compare node at ith position(ptr) with all nodes from the 
            //beginning of the list till we encounter a node whose rollNo
            //is greater than the node at ith position
            for (j = 1; j < i; ++j) {
                //move ptr2 to jth position
                ptr2 = move(start, j);
                //move temp2 to (j-1)th position
                temp2 = move(start, j - 1);
                //Check if rollno of ith node is less than rollNo of jth node
                if (ptr1->roll < ptr2->roll) {
                    //insert ith node before the node at jth position
                    temp1->next = ptr1->next;
                    ptr1->next = ptr2;
                    // if node at ith position is inserted at 1st position
                    //make list pointer start point to new first node
                    if (ptr2 == start) {
                        start = ptr1;
                    } else {
                        temp2->next = ptr1;
                    }
                    break; //terminate inner 'j' loop
                }
            }//end of j loop
        }//end of i loop
    }
    return start;
}

//function move returns the address of the i th
//node in the linked list from the start

NODE* move(NODE* start, int position) {
    NODE *ptr = NULL;
    if (!isListEmpty(start)) {
        if (position > 0) {
            ptr = start;
            while (position > 1) {
                ptr = ptr->next;
                --position;
            }
        }
    }
    return ptr;
}
