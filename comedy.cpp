
#include <string>
#include <iostream>
#include "media.h"
#include "comedy.h"
using namespace std;


Comedy::Comedy(char genre, int stock, string director, string title, int year)
        : Media('F', stock, director, title, year) {

}

Comedy::~Comedy(){
    // todo

}

void Comedy::display() const {
    cout << "F " << genre << " " << stock << " " << director << " " <<
         title << " " << year << endl;
}