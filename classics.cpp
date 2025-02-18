#include "classics.h"
#include <iostream>
#include "media.h"
using namespace std;

Classics::Classics(int stock, string director, string title,
                   string majorActor, int releaseMonth, int year)
        : Media('C', stock, director, title, year), majorActor(majorActor), releaseMonth(releaseMonth) {}


void Classics::display() const {
    cout << "Classics - " << title << " (" << releaseMonth << "/" << year
              << "), Directed by " << director << ", Starring: " << majorActor
              << ", Stock: " << stock << endl;
}
