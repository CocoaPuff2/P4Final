
#include <string>
#include <iostream>
#include "media.h"

using namespace std;

Media::Media(char genre, int stock, const string& director, const string& title, int year)
        : genre(genre), stock(stock), director(director), title(title), year(year) {}

// getters
char Media::getGenre() const { return genre; }
int Media::getStock() const { return stock; }

string Media::getDirector() const { return director; }
string Media::getTitle() const { return title; }
int Media::getYear() const { return year; }

// basic display
void Media::display() const {
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
