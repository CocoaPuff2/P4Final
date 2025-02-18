
#include <string>
#include <iostream>
#include "media.h"

using namespace std;

#ifndef MY_EXECUTABLE_COMEDY_H
#define MY_EXECUTABLE_COMEDY_H

class Comedy : public Media {
public:
    Comedy(int stock, string director, string title, int year);
    void display() const override;
};

#endif //MY_EXECUTABLE_COMEDY_H
