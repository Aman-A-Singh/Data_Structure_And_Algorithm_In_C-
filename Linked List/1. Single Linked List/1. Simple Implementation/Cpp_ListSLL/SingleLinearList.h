/* 
 * File:   SingleLinearList.h
 * Author: Aman Singh
 *
 * Created on 23 May 2021, 6:34 pm
 */

#ifndef SINGLELINEARLIST_H
#define SINGLELINEARLIST_H

struct STUDENT {
    int roll;
    std::string name;
    struct STUDENT *next;
};
typedef struct STUDENT NODE;

/* Accept data in the Node; takes a NODE pointer as parameter
 * in which the data is to be stored */
void acceptNodeData(NODE*);

/* Checks whether the list is empty; returns true if the list is empty
 * otherwise returns false.
 * Takes list pointer as its parameter
 */
bool isListEmpty(NODE *);

/* creates a single linear linked.
 * Allocates memory for the new NODE;
 * On success returns the address of newly allocated node;
 * On Failure returns NULL
 * Takes the list pointer as its parameter
 */
NODE* createList_or_append(NODE *);

/* creates a single linear linked.
 * Allocates memory for the new NODE;
 * On success returns the address of newly allocated node;
 * On Failure returns NULL
 * Takes the list pointer as its parameter
 */
NODE* createList_or_append(NODE *);

/*display all nodes from the list*/
void displayList(NODE *);

/* insert new node after the given roll no; 
 * takes the List pointer and the roll no. as its parameter*/
void insertNode(NODE *, int rollNo);

/*insert node at a specified position;
 * Takes two parameter; 1) the List pointer and 2) the Position */
NODE* insertNodeByPosition(NODE *, size_t postion);

//deletion by specifying the node position
NODE* deleteNodeByPosition(NODE *, size_t position);

//deletion by searching for the name
NODE* deleteNodeByName(NODE *, std::string nameToBeDeleted);

//reverse the linked list
NODE* reverseList(NODE *);

//count number of node in the list
size_t countNodes(NODE*);

//sort the list in ascending order
NODE* sort(NODE*);

//Returns the address to the node at specified position
NODE* move(NODE*, int position);

#define EXIT_CHOICE 10


#endif /* SINGLELINEARLIST_H */

