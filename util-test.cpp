#include <iostream>
#include <set>
#include "util.h"

using namespace std;

int main()
{

    set<int> evens = {0,2,4,6,8,10};
    set<int> odds = {1,3,5,7,9,10};

    set<int> tg = setUnion(evens, odds); // test union
    set<int> intersect = setIntersection(evens,odds); // test intersection func

    cout << "Union results: ";
    for (set<int>::iterator it = tg.begin();
        it != tg.end();
        ++it) {
        cout << *it << ", ";
    }

    cout << endl;

    cout << "Intersection results: ";
    for (set<int>::iterator it = intersect.begin();
        it != intersect.end();
        ++it) {
        cout << *it << ", ";
    }
    
    cout << endl;


    // testing parseStringToWords
    string sent1 = "I have too much caffeine";
    string sent2 = "csci 104 causes too much stress to do good I'll kms";
    string sent3 = "why did i choose this class";

    set<string> words1 = parseStringToWords(sent1);
    set<string> words2 = parseStringToWords(sent2);
    set<string> words3 = parseStringToWords(sent3);

    cout << endl << "Sentence 1 became" << endl;

    for (set<string>::iterator it = words1.begin();
        it != words1.end();
        ++it) {
            cout << *it << " ";
        }
        cout << endl;

    cout << endl << "Sentence 2 became" << endl;

    for (set<string>::iterator it = words2.begin();
        it != words2.end();
        ++it) {
            cout << *it << " ";
        }
        cout << endl;

    cout << endl << "And Sentence 3 became" << endl;

    for (set<string>::iterator it = words3.begin();
        it != words3.end();
        ++it) {
            cout << *it << " ";
        }
        cout << endl;

    return 0;
}