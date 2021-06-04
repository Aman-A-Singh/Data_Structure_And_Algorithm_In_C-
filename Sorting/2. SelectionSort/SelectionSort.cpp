/* 
 * File:   SelectionSort.cpp
 * Author: Aman Singh
 *
 * Created on 21 April 2021, 9:25 am
 */

#include <cstdlib>
#include <iostream>

using namespace std;
#define NUMBER_OF_ELEMENTS 5

void printSet(int [], size_t);
void acceptSet(int [], size_t);
void selectionSort(int [], size_t);

int main() {

    int a[NUMBER_OF_ELEMENTS];

    acceptSet(a, NUMBER_OF_ELEMENTS);
    cout << "Elements in Array Before Sorting : " << endl;
    printSet(a, NUMBER_OF_ELEMENTS);

    selectionSort(a, NUMBER_OF_ELEMENTS);
    cout << "Elements in Array After Sorting : " << endl;
    printSet(a, NUMBER_OF_ELEMENTS);

    return 0;
}

void printSet(int arr[], size_t size) {
    for (int i{0}; i < size; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

void acceptSet(int arr[], size_t size) {
    cout << "Please Enter " << size << " Integers " << endl;
    for (int i{0}; i < size; i++) {
        cout << "Enter " << i + 1 << " element :";
        cin >> arr[i];
    }
}

void selectionSort(int arr[], size_t size) {
    int i{};
    int minIndex{};
    for (i; i < size-1; i++) {
        minIndex = i;
        for (int j{i+1}; j < size ; j++) {
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[minIndex],arr[i]);
    }

}