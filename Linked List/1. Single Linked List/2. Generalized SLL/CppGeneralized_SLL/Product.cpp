/* 
 * File:   Product.cpp
 * Author: Aman Singh
 * 
 * Created on 15 June 2021, 3:49 pm
 */

#include "Product.h"
#include <iomanip>

Product::Product() {
    description.clear();
    quantity = 0U;
    price = 0.0F;
}

Product::Product(const Product& orig) {
    description = orig.description;
    quantity = orig.quantity;
    price = orig.price;
}

Product::~Product() {
    description.clear();
    quantity = 0U;
    price = 0.0F;
}

std::string Product::getDescription() const {
    return description;
}

void Product::setDescription(std::string description) {
    if (!description.empty()) {
        this->description = description;
    } else {
        throw std::invalid_argument("The new description supplied is invalid!");
    }
}

float Product::getPrice() const {
    return price;
}

void Product::setPrice(float price) {
    if (price > 0.0F) { //potential problem
        this->price = price;
    } else {
        throw std::invalid_argument("The new price supplied invalid!");
    }

}

uint32_t Product::getQuantity() const {
    return quantity;
}

void Product::setQuantity(uint32_t quantity) {
    if (quantity > 0) {
        this->quantity = quantity;
    } else {
        throw std::invalid_argument("The quantity supplied is invalid!");
    }

}

Product::Product(std::string description, float price, uint32_t quantity) {
    if (quantity > 0) {
        this->quantity = quantity;
    } else {
        throw std::invalid_argument("The quantity supplied is invalid!");
    }
    if (price > 0.0F) { //potential problem
        this->price = price;
    } else {
        throw std::invalid_argument("The new price supplied invalid!");
    }
    if (!description.empty()) {
        this->description = description;
    } else {
        throw std::invalid_argument("The new description supplied is invalid!");
    }
}

std::ostream& operator<<(std::ostream& out, Product &aproduct) {
    std::cout << std::setw(20)
            << std::setiosflags(std::ios::left)
            << "Description : " << std::setw(20) << aproduct.getDescription()
            << std::endl;
    std::cout << std::setw(20)
            << "Price       : " << std::setw(10) << std::setprecision(2)
            << std::setiosflags(std::ios::fixed)
            << aproduct.getPrice()
            << std::endl;
    std::cout << std::setw(20)
            << "Quantity    : " << std::setw(10) << aproduct.getQuantity()
            << std::endl << std::endl;

    return out;
}
