
/* 
 * File:   main.cpp
 * Author: Aman Singh
 *
 * Created on 23 May 2021, 6:33 pm
 */

#include <cstdlib>
#include <iostream>
#include "SingleLinearList.h"

#define CREATE_LIST 1
#define DISPLAY_LIST 2
#define INSERT_AFTER_ROLL_NO 3
#define INSERT_BY_POSITION 4
#define DELETE_BY_POSTION 5
#define DELETE_BY_NAME 6
#define REVERSE_LIST 7
#define COUNT_NODES 8
#define SORT_LIST 9
#define EXIT_CHOICE 10

int displayMenuChoice(void);

using namespace std;

int main() {
    NODE *start = NULL;
    string nameToDelete;
    int choice;
    int position;
    int rollNo;
    do {
        choice = displayMenuChoice();
        switch (choice) {
            case CREATE_LIST:
                start = createList_or_append(start);
                break;
            case DISPLAY_LIST:
                displayList(start);
                break;
            case INSERT_AFTER_ROLL_NO:
                cout << "\tAfter which roll number do you want to insert new node: ";
                cin >> rollNo;
                insertNode(start, rollNo);
                break;
            case INSERT_BY_POSITION:
                cout <<"\tPlease enter the position number ";
                cin >> position;
                start = insertNodeByPosition(start, position);
                break;
            case DELETE_BY_POSTION:
                cout << "\tEnter position of the node to be deleted : ";
                cin >> position;
                start = deleteNodeByPosition(start, position);
                break;
            case DELETE_BY_NAME:
                cout << "\tEnter the name of the student to be deleted : ";
                cin >> nameToDelete;
                start = deleteNodeByName(start, nameToDelete);
                break;
            case REVERSE_LIST:
                start = reverseList(start);
                cout << "\tThe list has been reversed\n";
                break;
            case COUNT_NODES:
                cout << "\tNumber of nodes = " <<  countNodes(start) << endl;
                break;
            case SORT_LIST:
                start = sort(start);
                cout << "\tThe list has been sorted\n";
                break;
            case EXIT_CHOICE:
                cout << "\tFinished with list operations !!\n ";
                break;
            default:
                cout << "\n\tIncorrect choice !!! \n";
        }
    } while (choice != EXIT_CHOICE);
    return EXIT_SUCCESS;
}

int displayMenuChoice(void) {
    int choice;
    bool isScanSuccessful = false;
        cout << "\n\t**** OPERATIONS ON SINGLE LINKED LIST  ****\n";
        cout << "\t1] Create List or Append the List\n";
        cout << "\t2] Display  List \n";
        cout << "\t3] Insert node in the List (after specified Roll No)\n";
        cout << "\t4] Insert node By Position \n";
        cout << "\t5] Delete node from the List ( By Position )\n";
        cout << "\t6] Delete node from the List ( By Name )\n";
        cout << "\t7] Reverse List \n";
        cout << "\t8] Count Nodes in the List \n";
        cout << "\t9] Sort the list(After Creation)\n";
        cout << "\t10] Exit\n";
        cout << "\n\tPlease enter your choice (1/2/3/4/5/6/7/8/9/10 ): ";
        cin >> choice ;
    return choice;
}
