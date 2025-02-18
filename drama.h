
#include <string>
#include <iostream>
#include "media.h"

using namespace std;

#ifndef MY_EXECUTABLE_DRAMA_H
#define MY_EXECUTABLE_DRAMA_H

class Drama : public Media {
    Drama(int stock, string director, string title, int year);
    void display() const override;
};

#endif //MY_EXECUTABLE_DRAMA_H
