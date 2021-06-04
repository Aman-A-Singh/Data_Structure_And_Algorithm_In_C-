/* 
 * File:   InsertionSort.cpp
 * Author: Aman Singh
 * Created on 21 April 2021, 11:28 am
 */

#include <cstdlib>
#include <iostream>

using namespace std;
#define NUMBER_OF_ELEMENTS 5

template<typename T>
void selectionSort(T arr[], size_t size) {
    for (int i{}; i < (size - 1); i++) {
        int minIndex{i};
        for (int j{i + 1}; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

template<typename T>
void printSet(T arr[], size_t size) {
    for (int i{0}; i < size; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

//template<typename T>
//void acceptSet(T arr[], size_t size) {
//    cout << "Please Enter " << size << " Elements " << endl;
//    for (int i{0}; i < size; i++) {
//        cout << "Enter " << i + 1 << " element :";
//        cin >> arr[i];
//    }
//}

int main() {
    int a[NUMBER_OF_ELEMENTS];
    
//    acceptSet(a, NUMBER_OF_ELEMENTS);
    cout << "Elements in Array Before Sorting : " << endl;
    printSet(a, NUMBER_OF_ELEMENTS);

    selectionSort(a, NUMBER_OF_ELEMENTS);
    cout << "Elements in Array After Sorting : " << endl;
    printSet(a, NUMBER_OF_ELEMENTS);

    return 0;
    return 0;
}
