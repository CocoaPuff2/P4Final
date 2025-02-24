#include "drama.h"
#include <iostream>
using namespace std;

Drama::Drama(char genre, int stock, string director, string title, int year)
        : Media(genre, stock, director, title, year) {

}

Drama::~Drama() {
   // todo:
}

void Drama::display() const {
    cout << "D " << genre << " " << stock << " " << director << " " <<
         title << " " << year << endl;
}