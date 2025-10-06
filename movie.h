#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <iostream>
#include <set>
#include "product.h"

using namespace std;


// study product.h and product.cpp
    // see what you don't need to change and
    // 

class Movie : public Product {
public: 

    Movie(const string& category, const string& name, double price, int qty, const string& genre, const string& rating);

    ~Movie();

    // returns the appropriate keywords to index the product
    std::set<std::string> keywords() const;

    // create a string that contains the product info
    std::string displayString() const;

    // outputs the database format of the product info
    void dump(std::ostream& os) const;


    // Book specific accessors and mutators
    string getGenre() const;
    string getRating() const;

private:
//Movies in addition to being normal products also contain
    // Genre
    // Rating
// in this order
string genre_;
string rating_;

};

#endif