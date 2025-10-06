#include <iostream>
#include <sstream>
#include <set>
#include <string>

#include "book.h"
#include "util.h"

using namespace std;

// helper func to print sets
void printer(const set<string>& s) {
    for (string p : s) {
        cout << p << ", ";
    }
    cout << endl;
}

int main()
{
    // initialize
    Book b("book", "How to code for dummies", 69.67, 420, "978-000000000-1", "Sean Cheng");

    // accessors and mutator section
    cout << "Book name: " << b.getName() << endl;
    cout << "Price: " << b.getPrice() << endl;
    cout << "Author Name: " << b.getAuthor() << endl;
    cout << "there are this many left: " << b.getQty() << endl;
    cout << "and the ISBN is " << b.getISBN() << endl << endl;


    // keywords test
    set<string> keywordsneeded = b.keywords();
    cout << "list of keywords in alphabetical order: ";
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
