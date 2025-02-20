
#include <string>
#include <iostream>
#include "media.h"

using namespace std;

Media::Media() {
    genre = ' ';
    stock = 0;
    director = " ";
    title = " ";
    year = 0;
}

Media::Media(char genre, int stock, const string& director, const string& title, int year)
        : genre(genre), stock(stock), director(director), title(title), year(year) {}

Media::~Media() {

}

// getters
char Media::getGenre() const { return genre; }
int Media::getStock() const { return stock; }
string Media::getDirector() const { return director; }
string Media::getTitle() const { return title; }
int Media::getYear() const { return year; }

// setters
void Media::setStock(int newStock) {
   stock = newStock;
}

void Media::setMedia(Media *newMedia) {
    nextMedia = newMedia;
}

Media* Media::getMedia() {
    return nextMedia;
}

// keep default
int Media::getReleaseMonth()
{
    return 0;
}
string Media::getMajorActorFirstName()
{
    return " ";
}
string Media::getMajorActorLastName()
{
    return " ";
}


// basic display
void Media::displayMedia() const {
    std::cout << "Title: " << title << ", Director: " << director
              << ", Year: " << year << ", Stock: " << stock << std::endl;
}














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
