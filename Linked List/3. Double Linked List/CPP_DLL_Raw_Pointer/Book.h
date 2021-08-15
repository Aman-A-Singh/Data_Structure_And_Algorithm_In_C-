#pragma once
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
    bool operator==(const Book&);
private:
    std::string title;
    std::string author;
    unsigned int price;
};

std::ostream& operator << (std::ostream& out, Book&);
/* BOOK_H */
