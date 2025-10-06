#include <iostream>
#include <set>
#include <string>
#include <iomanip>
#include <sstream>

#include "clothing.h"
#include "product.h"
#include "util.h"

using namespace std;

    // constructor
    Clothing::Clothing(const string& category, const string& name, double price, int qty, const string& size, const string& brand) : 
                Product(category, name, price, qty), 
                size_(size), 
                brand_(brand) 
        {}
    
    //deconstructor
    Clothing::~Clothing() {};


    // FINISH
    set<string> Clothing::keywords() const 
    {
        //general set to collect author names, make sure to parse string to individual words
        set<string> collector = parseStringToWords(convToLower(getBrand()));

        // set of keys to add book names that I with
        set<string> ProdKeys = parseStringToWords(convToLower(getName()));
        
        // add bookkeys to overall collector set
        for (set<string>::iterator it = ProdKeys.begin(); 
            it != ProdKeys.end();
            ++it) {
                collector.insert(*it);
            }

        return collector;
    };

    // FINISH
    std::string Clothing::displayString() const {
            // string total = getName() + "\n" + 
            //        "Size: " + getSize() + " Brand: " + getBrand() + "\n" + // product specific
            //      to_string(getPrice()) + " " + to_string(getQty()) + " left.";

            // return total;



            std::ostringstream oss;
            oss << getName() << "\n"
                << "Size: " << getSize() << " Brand: " << getBrand() << "\n"
                << std::fixed << std::setprecision(2) << getPrice()
                << " " << getQty() << " left.";
            return oss.str();
    }

    // FINISH
    void Clothing::dump(std::ostream& os) const{
        
        os << "clothing" << endl;
        os << getName() << endl;
        os << fixed << setprecision(2) << getPrice() << endl;
        os << getQty() << endl;
        
        // book specific
        os << getSize() << endl;
        os << getBrand() << endl;

    }

    string Clothing::getSize() const {
        return size_;
    }

    string Clothing::getBrand() const {
        return brand_;
    }