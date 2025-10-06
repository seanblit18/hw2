#include <iostream>
#include <sstream>
#include <set>
#include <string>

#include "clothing.h"
#include "util.h"

using namespace std;

// helper func to print sets for keywords
void printer(const set<string>& s) {
    for (string p : s) {
        cout << p << ", ";
    }
    cout << endl;
}

int main()
{
    // initialize
    Clothing b("Clothing", "Denim Jacket", 20, 4, "Medium", "Louis Vuitton");

    // accessors and mutator section
    cout << "Clothing Item: " << b.getName() << endl;
    cout << "Price: " << b.getPrice() << endl;
    cout << "Size: " << b.getSize() << endl;
    cout << "there are this many left: " << b.getQty() << endl;
    cout << "the piece comes from " << b.getBrand() << endl << endl;


    // keywords test
    set<string> keywordsneeded = b.keywords();
    cout << "list of keywords in alpha order: ";
    printer(keywordsneeded);
    cout << endl;

    // display test
    cout << "the display function displays the following:" << endl;
    cout << b.displayString() << endl << endl;


    // dumpy test :3
    cout << "meanwhile the dump test shows this DUMPY" << endl;
    b.dump(cout);
    cout << endl;
    
    return 0;
}
