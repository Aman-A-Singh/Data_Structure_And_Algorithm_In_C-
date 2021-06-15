/* 
 * File:   Book.h
 * Author: Aman Singh
 *
 * Created on 15 June 2021, 3:59 pm
 */

#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
public:
    Book();
    Book(const Book& orig);
    Book(std::string title, std::string author, unsigned price);
    virtual ~Book();
    std::string getTitle() const;
    std::string getAuthor() const;
    unsigned int getPrice() const;
private:
    std::string title;
    std::string author;
    unsigned int price;
};

std::ostream& operator<<(std::ostream& out, Book &);
#endif /* BOOK_H */

