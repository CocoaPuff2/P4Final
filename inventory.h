#include "media.h"
#include <vector>
#include <unordered_map>

using namespace std;

#ifndef MY_EXECUTABLE_INVENTORY_H
#define MY_EXECUTABLE_INVENTORY_H

// maintain a collection of movies
class Inventory {
private:
    unordered_map<string, Media*> mediaList; // store movie objects
public:
    ~Inventory();
    void addMedia(Media* media);
    void borrowItem(const std::string& title);
    void returnItem(const std::string& title);
    void displayInventory() const;
};

#endif //MY_EXECUTABLE_INVENTORY_H
