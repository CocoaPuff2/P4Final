
#include <string>
#include <iostream>
#include "media.h"

using namespace std;

#ifndef MY_EXECUTABLE_COMEDY_H
#define MY_EXECUTABLE_COMEDY_H

class Comedy : public Media {
public:
    Comedy(char genre, int stock, string director, string title, int year);
    ~Comedy();
    // specifically for comedies, overrides the media version
    // const so that it doesn't modify the data, only reads it
    void display() const;
};

#endif //MY_EXECUTABLE_COMEDY_H
