#include "inventory.h"
#include "media.h"
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

Inventory::~Inventory() {
    for (auto& entry : mediaList) {
        delete entry.second;  // delete dynamically alloc mem
    }
}

void Inventory::addMedia(Media* media) {
    char genre = media->getGenre();
    if (genre != 'C' && genre != 'D' && genre != 'F') {
        std::cout << "ERROR: " << genre << " Invalid Genre. Try Again." << std::endl;
        delete media; // delete invalid movie object ( avoid mem leak )
        return;
    }

    mediaList[media->getTitle()] = media; // adds valid medias to inventory
}

void Inventory::borrowItem(const std::string& title) {
    // Find the item in the inventory
    auto it = mediaList.find(title);
    if (it != mediaList.end()) {
        // Check if the item is available for borrowing
        if (it->second->getStock() > 0) {
            // todo
            it->second->decreaseStock();  // Decrease stock for the borrowed item
            cout << "Successfully borrowed: " << title << std::endl;
        } else {
            cout << "Borrow Transaction Failed -- Not enough in the Stock" << endl;
        }
    } else {
        cout << "Borrow Transaction Failed -- Movie does not Exist in the Inventory" << endl;
    }

}


// Display the inventory of movies in the store
void Inventory::displayInventory() const {
    vector<Media*> comedyMovies;
    vector<Media*> dramaMovies;
    vector<Media*> classicsMovies;

    // Separate movies into different categories
    for (const auto& pair : mediaList) {
        if (pair.second->getGenre() == 'F') {
            comedyMovies.push_back(pair.second);
        } else if (pair.second->getGenre() == 'D') {
            dramaMovies.push_back(pair.second);
        } else if (pair.second->getGenre() == 'C') {
            classicsMovies.push_back(pair.second);
        }
    }

    // Output all Comedy movies first
    std::cout << "Comedies: \n";
    for (const auto& movie : comedyMovies) {
        movie->display();  // display() from Media class
    }

    // Output all Drama movies second
    std::cout << "\nDramas: \n";
    for (const auto& movie : dramaMovies) {
        movie->display();
    }

    // Output all Classics movies last
    std::cout << "\nClassicss: \n";
    for (const auto& movie : classicsMovies) {
        movie->display();
    }
}

