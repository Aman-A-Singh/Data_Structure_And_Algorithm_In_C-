/* 
 * File:   main.cpp
 * Author: Aman Singh
 * Created on 22 April 2021, 4:33 pm
 */

#include <cstdlib>
#include <iostream>

using namespace std;
#define SIZE 10

void printSet(int [], size_t);
void acceptSet(int [], size_t);
void counting_sort(int [], size_t);

int main() {
    int arr[SIZE]{5, 2, 5, 3, 6, 1, 5, 3, 9, 6};
    //accept(arr,SIZE);
    cout << "Elements int the Array Before Sorting :" << endl;
    printSet(arr, SIZE);

    cout << "Elements int the Array After Sorting :" << endl;
    counting_sort(arr, SIZE);

    return 0;
}

void printSet(int arr[], size_t size) {
    for (int i{}; i < size; i++) {
        cout << arr[i] << ',';
    }
    cout << endl;
}


//Function Implementing the Counting Sort

void counting_sort(int arr[], size_t size) {

    //Step 1: Finding the maximum element
    int maximum = -1;

    for (int i{}; i < size; i++) {
        if (arr[i] > maximum) {
            maximum = arr[i];
        }
    }

    //Step 2: Initialize a count array of length = (maximum+1)
    int count[maximum + 1]{};

    //Step 3: Set the count array accordingly
    for (int i{}; i < size; i++) {
        count[arr[i]]++;
    }

    //Step 4: Calculate cumulative frequency in Count Array
    for (int i{1}; i <= maximum; i++) {
        count[i] += count[i - 1];
    }

    //Step 5: Fixed the values in the sorted array
    int sorted_arr[size];

    for (int i{}; i < size; i++) {
        sorted_arr[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    printSet(sorted_arr, SIZE);
}