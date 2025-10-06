#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
#include <set>
#include "product.h"

using namespace std;


// study product.h and product.cpp
    // see what you don't need to change and
    // 

class Book : public Product {
public: 
    // constructor
    Book(const string& category, const string& name, double price, int qty, const string& isbn, const string& author);

    // deconstructor
    ~Book();

    // returns the appropriate keywords to index the product
    std::set<std::string> keywords() const;

    // create a string that contains the product info
    std::string displayString() const;

    // outputs the database format of the product info
    void dump(std::ostream& os) const;


    // Book specific accessors and mutators
    string getISBN() const;
    string getAuthor() const;

private:
//books in addition to being normal products also contain
    // ISBN
    // author name
// in this order
string isbn_;
string author_;

};

#endif