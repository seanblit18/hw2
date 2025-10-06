#include <string>
#include <iostream>
#include "mydatastore.h"
#include "product_parser.h"
#include "util.h"

using namespace std;

    myDataStore::~myDataStore() {
    // deleting prods
    for (vector<Product*>::iterator prodit = product_.begin();
        prodit !=product_.end();
        prodit++)
    {
        delete *prodit;
    }

    // deleting users
    for (map<string, User*>::iterator useit = user_.begin();
        useit != user_.end();
        useit++) {
            delete useit->second;
        }
}



void myDataStore::addProduct(Product* p) {
    product_.push_back(p);
    return;
}

void myDataStore::addUser(User* u) {
    string username = convToLower(u->getName());
    user_[username] = u;
    return;
}

vector<Product*> myDataStore::search(vector<string>& terms, int type) {
    set<Product*> matches;
    set<Product*> matches2;
    
    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */

    // if terms list is empty (nothing in search bar)
    if (terms.empty()) {return vector<Product*>();}

    /*// if terms list = 1
    for (vector<Product*>::iterator it = product_.begin();
        it != product_.end();
        ++it) 
    {
        set<string> matcha = (*it)->keywords();
        if (matcha.find(convToLower(terms[0])) != matcha.end()) {
            matches.insert(*it);
        }
    } */

    // if multiple words, 
    for (size_t i = 0; i < terms.size(); i++) { // start at SECOND which is index 1
        for (vector<Product*>::iterator it = product_.begin();
        it != product_.end();
        ++it) 
        {
            set<string> matcha = (*it)->keywords();
            if (matcha.find(convToLower(terms[i])) != matcha.end()) {
                if (i == 0) {
                    matches.insert(*it); // set of prods from first term
                }
                else {
                    matches2.insert(*it); // set of prods from all other terms
                }
            }
        }

    }

    if (type == 0) // AND search
    {
        matches = setIntersection(matches, matches2);
    }

    else if (type == 1) // OR search
    {
        matches = setUnion(matches, matches2);
    }

    else { // wrong type
        return vector<Product*>();
    }

    vector<Product*> final;
    final.assign(matches.begin(), matches.end());
    return final; 

}

void myDataStore::dump(ostream& ofile) {
    // product
    ofile << "<products>" << endl;
    for (vector<Product*>::iterator it = product_.begin();
        it != product_.end();
        it++) 
    {
        (*it)->dump(ofile);
    }
    ofile << "</products>" << endl;

    // user
    ofile << "<users>" << endl;
    for (map<string, User*>::iterator it = user_.begin();
        it != user_.end();
        it++) 
    {
        it->second->dump(ofile);
    }
    ofile << "</users>" << endl;
}

void myDataStore::viewCart(const string& u) {
    string sam = convToLower(u);

    // find sam
    map<string, User*>::iterator it = user_.find(sam);
    
    // if sam is unfound, 
    if (it == user_.end()) {
        cout << "Invalid username" << endl;
        return;
    }

    // if sam found, and he has valid cart
    if (cart_.find(sam) != cart_.end()) {
        // iterate through the cart and print
        const deque<Product*>& carti = cart_[sam];
        for (size_t i = 0; i < carti.size(); ++i) {
            cout << "Item " << (i+1) << endl;
            cout << carti[i]->displayString() << endl;
        }      
    }
}

void myDataStore::addtoCart(Product* p, const string& u) {
    string hellokitty = convToLower(u);
    if (p == nullptr) {return;}

    // if user exists,
    if (user_.find(hellokitty) != user_.end()) {
        // add product to cart
        cart_[hellokitty].push_back(p);
    }
    //if user dne,
    else {
        cout << "Invalid request" << endl;
    }


}

void myDataStore::buyCart(const string& u) {
    string ferrari = convToLower(u);
    
    map<string, User*>::iterator charles = user_.find(ferrari);
    if (charles == user_.end()) {
        cout << "Invalid username" << endl;
        return;
    }

    User* lewis = charles->second;

    map<string, deque<Product*>>::iterator max = cart_.find(ferrari);
    if (max == cart_.end()) {
        return; // empty kart
    }

    deque<Product*>& cart = max->second;

    size_t n = cart.size();
    for (size_t i = 0; i < n; i++) {
        Product* prodih = cart.front();
        cart.pop_front();

        if (prodih != nullptr && prodih->getQty()> 0 &&
            lewis->getBalance() >= prodih->getPrice()) {
                lewis->deductAmount(prodih->getPrice());
                prodih->subtractQty(1);
            }
        else {cart.push_back(prodih);}
    }

    /*User* charles = user_[ferrari];

    // if user exists
    if (cart_.find(ferrari) != cart_.end()) {
        // name user's specific cart

        map<string, deque<Product*>>::iterator carts = cart_.find(u);
        deque<Product*> carti = carts->second;


        // check if qty enough && user rich enough at each iteration
        for (size_t i = 0; i < carti.size(); i++) {
            
            Product* iter = carti.front();
            carti.pop_front();
            double budget = charles->getBalance(); // def budget
            int stock = carti[i]->getQty(); // def stock

            if (iter != nullptr && 
                budget >= iter->getPrice() && 
                stock > 0)
            {
                charles->deductAmount(carti[i]->getPrice()); // lower balance
                iter->subtractQty(1); // subtract quantity by 1
            }
        }
    }
    
    //if user dne,
    else {
        cout << "Invalid username" << endl;
    }*/

    return;
}

