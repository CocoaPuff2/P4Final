#include "drama.h"
#include <iostream>
using namespace std;

Drama::Drama(int stock, string director, string title, int year)
        : Media('D', stock, director, title, year) {

}
Drama::~Drama() {

}

void Drama::display() const {
    cout << "D " << genre << " " << stock << " " << director << " " <<
         title << " " << year << endl;
}