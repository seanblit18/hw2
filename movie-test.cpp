#include <iostream>
#include <sstream>
#include <set>
#include <string>

#include "movie.h"
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
    Movie b("movie", "Spider-Man: Across the Spider-Verse", 123456.02, 676767, "Drama", "5 stars!");

    // accessors and mutator section
    cout << "Movie name: " << b.getName() << endl;
    cout << "Price: " << b.getPrice() << endl;
    cout << "Genre: " << b.getGenre() << endl;
    cout << "there are this many left: " << b.getQty() << endl;
    cout << "my Letterboxd rating is " << b.getRating() << endl << endl;


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
