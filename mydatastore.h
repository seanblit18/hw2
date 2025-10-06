#ifndef MYDATASTORE_H
#define MYDATASTORE_H

#include <map>
#include <string>
#include <iostream>
#include <deque>
#include "datastore.h"
#include "product.h"
#include "user.h"

using namespace std;

class myDataStore : public DataStore {
public: 
    
    ~myDataStore();

    void addProduct(Product* p);

    void addUser(User* u);

    vector<Product*> search(vector<string>& terms, int type);

    void dump(std::ostream& ofile);


    // cart funcs
    void viewCart(const string& u);
    void addtoCart(Product* p, const string& u);
    void buyCart(const string& u);

private:
    vector<Product*> product_;
    map<string, User*> user_;
    map<string, deque<Product*>> cart_;
};


#endif