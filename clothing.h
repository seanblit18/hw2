#ifndef CLOTHING_H
#define CLOTHING_H

#include <string>
#include <iostream>
#include <set>
#include "product.h"

using namespace std;


// study product.h and product.cpp
    // see what you don't need to change and
    // 

class Clothing : public Product {
public: 
    // constructor 
    Clothing(const string& category, const string& name, double price, int qty, const string& size, const string& brand);

    // destructor

    ~Clothing();
    
    // returns the appropriate keywords to index the product
    std::set<std::string> keywords() const;

    // create a string that contains the product info
    std::string displayString() const;

    // outputs the database format of the product info
    void dump(std::ostream& os) const;


    // Book specific accessors and mutators
    string getSize() const;
    string getBrand() const;

private:
//clothing in addition to being normal products also contain
    // Size
    // Brand
// in this order
string size_;
string brand_;

};

#endif