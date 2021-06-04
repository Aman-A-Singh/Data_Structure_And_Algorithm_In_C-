/* 
 * File:   BubbleSortOptimized.cpp
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
    bubbleSort(arr, NUMBER_OF_ELEMENTS);
    cout << "The sorted numbers are : " << endl;
    printSet(arr, NUMBER_OF_ELEMENTS);
    return 0;
}

void bubbleSort(int a[], size_t size) {
    int j;
    int i;
    bool swapped;
    //Using do while loop
//    i = size;
//    do {
//        swapped = false;
//        for (j = 0; j < (i - 1); j++) {
//            if (a[ j ] > a[ j + 1 ]) {
//                //swap two elements at (j)th and (j+1)th position
//                swap(a, j, j + 1);
//                swapped = true; //if elements are swapped
//            }
//        }//end of inner j loop
//        i = i - 1;
//    } while (swapped == true);

    //using for loop
    //loop for controling total number of passes
    for (i = 1; i <= size; i++) {
        swapped = false;//reset if swap is done
        //loop for controling number of
        //comparison during each pass
        for (j = 0; j < (size - i); j++) {
            if (a[ j ] > a[ j + 1 ]) {
                //swap two elements at (j)th and (j+1)th position
                swap(a, j, j + 1);
                swapped = true;//if swap is done in any pass
            }
        }//end of inner j loop
        if(swapped == false) {
            break;//if no swap is done in any pass
                  //means array is already sorted
        }
    }//end of outer i loop
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