
#include <string>
#include <iostream>
#include "media.h"
#include "comedy.h"
using namespace std;


Comedy::Comedy(char genre, int stock, string director, string title, int year)
        : Media(genre, stock, director, title, year) {

/*
    : Media()
    genre = newGenre;
    stock = newStock;
    director = newDirector;
    title = newTitle;
    year = newYear;
 */
}

Comedy::~Comedy(){
    // todo

}

void Comedy::display() const {
    cout << "F " << genre << " " << stock << " " << director << " " <<
         title << " " << year << endl;
}