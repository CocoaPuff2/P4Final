
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
    // adds majorActor and releaseMonth
    Classics(char genre, int stock, const string& director, const string& title,
             string  majorActorFirstName, string majorActorLastName, int releaseMonth, int year);

    ~Classics();

    void display() const; // specifically for classics, overrides the media version

    string getMajorActorFirstName();
    string getMajorActorLastName();

    int getReleaseMonth();

};


#endif //MY_EXECUTABLE_CLASSICMOVIE_H
