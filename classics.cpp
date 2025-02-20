#include "classics.h"
#include <iostream>
#include <utility>
#include "media.h"
using namespace std;

Classics::Classics(char newGenre, int newStock, const string& newDirector, const string& newTitle,
                   string newMajorActorFirstName, string newMajorActorLastName, int newReleaseMonth, int newYear) {
    genre = newGenre;
    stock = newStock;
    director = newDirector;
    title = newTitle;
    majorActorFirstName = newMajorActorFirstName;
    majorActorLastName = newMajorActorLastName;
    releaseMonth = newReleaseMonth;
    year = newYear;
}

Classics::~Classics() {

}


string Classics::getMajorActorFirstName() {
    return majorActorFirstName;

}

string Classics::getMajorActorLastName() {
    return majorActorLastName;

}

int Classics::getReleaseMonth() {
    return releaseMonth;

}


void Classics::display() const {
    cout << "C " << genre << " " << stock << " " << director << " " <<
         title << " " << majorActorFirstName << " " << majorActorLastName << " " <<
         releaseMonth << " " << year << endl;
}
