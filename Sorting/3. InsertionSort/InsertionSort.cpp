/* 
 * File:   InsertionSort.cpp
 * Author: Aman Singh
 * Created on 21 April 2021, 11:28 am
 */

#include <cstdlib>
#include <iostream>

using namespace std;
#define SIZE 10

void printArray(int [], size_t);
void acceptSet(int [], size_t);
void insertion_sort(int [], size_t);

int main() {
    int arr[SIZE] = {12, 34, 56, 78, 3, 2, 1, 4, 5, 9};
    //acceptSet(arr, SIZE);
    cout << "Elements in Array Before Sorting : " << endl;
    printArray(arr, SIZE);
    insertion_sort(arr, SIZE);
    cout << "Elements in Array After Sorting : " << endl;
    printArray(arr, SIZE);
    return (EXIT_SUCCESS);
}

void printArray(int arr[], size_t size) {
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

void insertion_sort(int arr[], size_t size) {
    int position{};
    int currentvalue{};
    int index{};
    for (index = 1; index < size; index++) {
        currentvalue = arr[index];
        position = index;
        while (position > 0 && (arr[position - 1] > currentvalue)) {
            arr[position] = arr[position - 1];
            position = position-1;
        }
        arr[position] = currentvalue;
    }
}

