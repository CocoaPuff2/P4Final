
#include <string>
#include <iostream>
#include "media.h"

using namespace std;

#ifndef MY_EXECUTABLE_CLASSICMOVIE_H
#define MY_EXECUTABLE_CLASSICMOVIE_H

class Classics : public Media {
private:

    string majorActor; // Major actor for the classic movie
    int releaseMonth;  // Release month of the classic movie

public:
    // adds majorActor and releaseMonth
    Classics(int stock, const string& director, const string& title,
             string  majorActor, int releaseMonth, int year);

    void display() const override;

    // string getMajorActor() const;

   //  int getReleaseMonth() const;

};


#endif //MY_EXECUTABLE_CLASSICMOVIE_H
