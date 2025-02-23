
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
    void display() const; // specifically for comedies, overrides the media version
};

#endif //MY_EXECUTABLE_COMEDY_H
