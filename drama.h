
#include <string>
#include <iostream>
#include "media.h"

using namespace std;

#ifndef MY_EXECUTABLE_DRAMA_H
#define MY_EXECUTABLE_DRAMA_H

class Drama : public Media {
    Drama(char genre, int stock, string director, string title, int year);
    ~Drama();
    // specifically for dramas, overrides the media version
    // const so that it doesn't modify the data, only reads it
    void display() const;
};

#endif //MY_EXECUTABLE_DRAMA_H
