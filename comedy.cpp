
#include <string>
#include <iostream>
#include "media.h"
#include "comedy.h"
using namespace std;

Comedy::Comedy(int stock, string director, string title, int year)
        : Media('F', stock, director, title, year) {}

void Comedy::display() const {
    cout << "Comedy - " << title << " (" << year
              << "), Directed by " << director
              << ", Stock: " << stock << endl;
}