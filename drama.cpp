#include "drama.h"
#include <iostream>
using namespace std;

Drama::Drama(int stock, string director, string title, int year)
        : Media('D', stock, director, title, year) {}

void Drama::display() const {
    cout << "Drama - " << title << " (" << year
              << "), Directed by " << director
              << ", Stock: " << stock << endl;
}