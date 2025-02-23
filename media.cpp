
#include <string>
#include <iostream>
#include "media.h"

using namespace std;

// default constructor
Media::Media() {
    genre = ' ';
    stock = 0;
    director = " ";
    title = " ";
    year = 0;
}

// param constructor
Media::Media(char genre, int stock, const string& director, const string& title, int year)
        : genre(genre), stock(stock), director(director), title(title), year(year) {}


Media::~Media() {
 // since Media is abstract, it doesn't need a destructor because no direct objects of Media
 // can ever be instantiated.
}

// getters
char Media::getGenre() const { return genre; }
int Media::getStock() const { return stock; }
string Media::getDirector() const { return director; }
string Media::getTitle() const { return title; }
int Media::getYear() const { return year; }

// setters to set a new stock
void Media::setStock(int newStock) { stock = newStock;}
void Media::setMedia(Media *newMedia) { nextMedia = newMedia; } // sets next movie in LL (ptr)
Media* Media::getMedia() { return nextMedia;} //  return ptr to next movie in LL


// keep default, is for classics only
int Media::getReleaseMonth() { return 0;}
string Media::getMajorActorFirstName() { return " "; }
string Media::getMajorActorLastName() {return " "; }


// basic display
void Media::displayMedia() const {
    cout << "Is in the basic display for Media " << endl;
    cout << "Title: " << title << ", Director: " << director
              << ", Year: " << year << ", Stock: " << stock << std::endl;
}




/*
bool Media::borrowMovie() {
    if (stock > 0) {
        stock--;
        return true;
    }
    return false;
}

void Media::returnMovie() {
    stock++;
}
 */
