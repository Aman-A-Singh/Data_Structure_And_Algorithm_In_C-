/* 
 * File:   main.cpp
 * Author: Aman Singh
 *
 * Created on 15 June 2021, 1:01 pm
 */

#include <cstdlib>
#include <iostream>
#include "SingleLinearList.h"
#include "Product.h"
#include "Book.h"

using namespace std;

void testProduct();
void testBook();

int main() {
    //    testProduct();
    testBook();
    return EXIT_SUCCESS;
}

void testProduct() {
    try {
        SingleLinearList<Product> productList;
        std::cout << "Product List" << std::endl;
        Product p1("Box", 340.0F, 20);
        productList.append(p1);
        Product p2("Marker", 140.0F, 200);
        Product p3("Pen", 500.0F, 10);
        productList.append(p2);
        productList.append(p3);
        productList.print_list();
        productList.clear();
    } catch (std::range_error& err) {
        std::cerr << err.what() << std::endl;
    }
}

void testBook() {
    try {

        SingleLinearList<Book> bookList;
        Book b1("Tawan", "Premchand", 1250);
        bookList.append(b1);
        Book b2("History Of India", "Nehru", 2250);
        bookList.append(b2);
        Book b3("Wings of fire", "APJ", 1000);
        bookList.append(b3);
        bookList.print_list();
    } catch (std::range_error& err) {
        std::cerr << err.what() << std::endl;
    }
}