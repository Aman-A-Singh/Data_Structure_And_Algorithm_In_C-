/* 
 * File:   Product.h
 * Author: Aman Singh
 *
 * Created on 15 June 2021, 3:49 pm
 */

#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <cstdint>
#include <iostream>

class Product {
public:
    Product();
    Product(const Product& orig);
    virtual ~Product();
    Product(std::string description, float price, uint32_t quantity);
    /* Returns the description of the Product*/
    std::string getDescription() const;

    /* Method takes one argument of type string which is the new name of product */
    void setDescription(std::string description);

    /* Returns a float as price of the product*/
    float getPrice() const;

    /* Method takes a single argument of type float which is 
     * the new price of the product */
    void setPrice(float price);

    /* Returns an uint32_t which is the Quantity of the product*/
    uint32_t getQuantity() const;

    /* Takes a single uint32_t as agrument which is the new quantity*/
    void setQuantity(uint32_t quantity);

private:
    std::string description;
    float price;
    uint32_t quantity;

};

std::ostream& operator<<(std::ostream& out, Product &aproduct);

#endif /* PRODUCT_H */

