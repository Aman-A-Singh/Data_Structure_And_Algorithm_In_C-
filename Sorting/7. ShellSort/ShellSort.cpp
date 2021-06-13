/* 
 * File:   ShellSort.cpp
 * Author: Aman Singh
 *
 * Created on 25 April 2021, 6:14 PM
 */

#include <cstdlib>
#include "iostream"

#define SIZE 9

void printSet(int [], size_t);
void shellSort(int [], size_t, size_t);
void swap(int[], size_t, size_t);

int main() {
    std::cout << "********* Shell Sort *********" << std::endl;
    int arr[SIZE] = {9, 15, 6, 3, 8, 4, 12, 2, 5};
    size_t shell;
    if (SIZE % 2 == 0) {
        shell = SIZE / 2;
    } else {
        shell = SIZE / 2 + 1;
    }
    std::cout << "Elements in the array Before Sorting :" << std::endl;
    printSet(arr, SIZE);
    shellSort(arr, shell, SIZE);
    std::cout << "Elements in the array After Sorting :" << std::endl;
    printSet(arr, SIZE);
    return 0;
}

void printSet(int arr[], size_t size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ,";
    }
    std::cout << std::endl;
    return;
}

//void shellSort(int arr[], size_t shell, size_t size) {
//    for (int i = 0; i + shell < size; i++) {
//        if (arr[i] > arr[i + shell]) {
//            swap(arr, i, i + shell);
//        }
//    }
//    shell--;
//    if (shell != 0) {
//        shellSort(arr, shell, size);
//    }
//    return;
//}

void swap(int arr[], size_t i, size_t j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


//Non recursive Shell Sort

void shellSort(int arr[], size_t shell, size_t size) {
    while (shell != 0) {
        for (int i = 0; i + shell < size; i++) {
            if (arr[i] > arr[i + shell]) {
                swap(arr, i, i + shell);
            }
        }
        shell--;
    }
}