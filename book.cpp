#include <iostream>
#include <set>
#include <string>
#include <iomanip>
#include <sstream>

#include "book.h"
#include "product.h"
#include "util.h"

using namespace std;

    // constructor
    Book::Book(const string& category, const string& name, double price, int qty, const string& isbn, const string& author) : 
                Product(category, name, price, qty), 
                isbn_(isbn), 
                author_(author) 
        {

        }
    
    //deconstructor
    Book::~Book() {};


    // FINISH
    set<string> Book::keywords() const 
    {

        // figure out how to get keywords into collector
            // LOOK UNDER REQUIREMENTS FOR ITEM SPECIFIC KEYWORDS REQUIRED

        // book keywords require 
            // product name
            // author name
            // ISBN

        //general set to collect author names, make sure to parse string to individual words
        set<string> collector = parseStringToWords(convToLower(getAuthor()));

        // set of keys to add book names that I with
        set<string> bookkeys = parseStringToWords(convToLower(getName()));
        
        // add bookkeys to overall collector set
        for (set<string>::iterator it = bookkeys.begin(); 
            it != bookkeys.end();
            ++it) {
                collector.insert(*it);
            }
        

        // insert ISBN exactly, no changes
        collector.insert(isbn_);

        return collector;
    };

    // FINISH
    std::string Book::displayString() const {
    //can i clean this up?? looks ugly asf
            // string total = getName() + "\n" + 
            //        "Author: " + getAuthor() + " ISBN: " + getISBN() + "\n" + // product specific
            //      to_string(getPrice()) + " " + to_string(getQty()) + " left.";

            // return total;



            std::ostringstream oss;
            oss << getName() << "\n"
                << "Author: " << getAuthor() << " ISBN: " << getISBN() << "\n"
                << std::fixed << std::setprecision(2) << getPrice()
                << " " << getQty() << " left.";
            return oss.str();
    }

    // FINISH
    void Book::dump(std::ostream& os) const{
        
        os << "book" << endl;
        os << getName() << endl;
        os << getPrice() << endl;
        os << getQty() << endl;
        
        // book specific
        os << getISBN() << endl;
        os << getAuthor() << endl;

    }

    string Book::getISBN() const {
        return isbn_;
    }

    string Book::getAuthor() const {
        return author_;
    }



