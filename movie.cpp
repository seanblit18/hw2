#include <iostream>
#include <iomanip>
#include <set>
#include <string>
#include <sstream>

#include "movie.h"
#include "product.h"
#include "util.h"

using namespace std;

    // constructor
    Movie::Movie(const string& category, const string& name, double price, int qty, const string& genre, const string& rating) :
                Product(category, name, price, qty), 
                genre_(genre), 
                rating_(rating) 
                { }

    // destructor
    Movie::~Movie() {};

    // keywords
    set<string> Movie::keywords() const
    {
        set<string> collector = parseStringToWords(convToLower(getName()));
        collector.insert(convToLower(getGenre()));

        return collector;
    }

    // displayString
    string Movie::displayString() const {

        /*
        string total = getName() + "\n" + 
            "Genre: " + getGenre() + " Rating: " + getRating() + "\n" + // product specific
            to_string(getPrice()) + " " + to_string(getQty()) + " left.";

        return total;
        */

        std::ostringstream oss;
        oss << getName() << "\n"
            << "Genre: " << getGenre() << " Rating: " << getRating() << "\n"
            << std::fixed << std::setprecision(2) << getPrice()
            << " " << getQty() << " left.";
        return oss.str();
    }

    void Movie::dump(std::ostream& os) const{
        os << "movie" << endl;
        os << getName() << endl;
        os << fixed << setprecision(2) << getPrice() << endl;
        os << getQty() << endl;

        // movie specific
        os << getGenre() << endl;
        os << getRating() << endl;
    }

    string Movie::getGenre() const {
        return genre_;
    }

    string Movie::getRating() const {
        return rating_;
    }
    