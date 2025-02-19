#include "classics.h"
#include <iostream>
#include <utility>
#include "media.h"
using namespace std;

Classics::Classics(int stock, const string& director, const string& title,
                   string  majorActor, int releaseMonth, int year)
        : Media('C', stock, director, title, year), majorActor(std::move(majorActor)), releaseMonth(releaseMonth) {}


void Classics::display() const {
    cout << "Classics - " << title << " (" << releaseMonth << "/" << year
              << "), Directed by " << director << ", Starring: " << majorActor
              << ", Stock: " << stock << endl;
}
