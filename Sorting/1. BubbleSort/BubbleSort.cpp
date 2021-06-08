/* 
 * File:   BubbleSort.cpp
 * Author: Aman Singh
 *
 * Created on April 5, 2021, 3:44 PM
 */

#include <cstdlib>
#include <iostream>
// Not a good idea When you are accepting the elments or printing the elementsइ
#define NUMBER_OF_ELEMENTS 8 

using namespace std;

void bubbleSort(int [], size_t size);
void swap(int [], int i, int j);
void acceptSet(int [], size_t size);
void printSet(int [], size_t size);

int main() {
    int arr[ NUMBER_OF_ELEMENTS ];
    acceptSet(arr, NUMBER_OF_ELEMENTS);
    cout << "The original Numbers are :" << endl;
    printSet(arr, NUMBER_OF_ELEMENTS);
    cout << "The sorted numbers are : " << endl;
    bubbleSort(arr, NUMBER_OF_ELEMENTS);
    printSet(arr, NUMBER_OF_ELEMENTS);
    return 0;
}

void bubbleSort(int a[], size_t size) {
    int j;
    int i;
    int counter = 0;
    //loop for controling total number of passes
    for (i = 1; i <= size; i++) {
        //loop for controling number of
        //comparison during each pass
        for (j = 0; j < (size - i); j++) {
            counter++;
            if (a[ j ] > a[ j + 1 ]) {
                //swap two elements at (j)th and (j+1)th position
                swap(a, j, j + 1);
            }
        }//end of inner j loop
    }//end of outer i loop
    cout << "Number of Passes " << counter << endl;
    return;
}

void swap(int a[], int i, int j) {
    int temp = a[ i ];
    a[ i ] = a[ j ];
    a[ j ] = temp;
    return;
}

void acceptSet(int a[], size_t size) {
    cout << "Please enter " << size << " elements" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Enter the Value of " << i + 1 << " Element :";
        cin >> a[i];
    }
    return;
}

void printSet(int a[], size_t size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ,";
    }
    cout << endl;
}