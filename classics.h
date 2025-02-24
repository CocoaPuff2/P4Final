
#include <string>
#include <iostream>
#include "media.h"

using namespace std;

#ifndef MY_EXECUTABLE_CLASSICMOVIE_H
#define MY_EXECUTABLE_CLASSICMOVIE_H

class Classics : public Media {
private:

    string majorActorFirstName; // Major actor first name for the classic movie
    string majorActorLastName; //  Major actor first last for the classic movie
    int releaseMonth;  // Release month of the classic movie

public:
    // adds majorActorFirstName, majorActorLastName, and releaseMonth
    // todo & or not for director and title strings?
    Classics(char genre, int stock, const string director, const string title,
             string  majorActorFirstName, string majorActorLastName, int releaseMonth, int year);

    ~Classics();

    // specifically for classics, overrides the media version
    // const so that it doesn't modify the data, only reads it
    void display() const;

    // getters
    string getMajorActorFirstName();
    string getMajorActorLastName();
    int getReleaseMonth();

};


#endif //MY_EXECUTABLE_CLASSICMOVIE_H
