#include "inventory.h"
#include "media.h"
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

Inventory::~Inventory() {
    for (auto& entry : mediaList) {
        delete entry.second;  // delete dynamically alloc mem
    }
}

void loadMovies(const string& filename) {
    ifstream infile("data4movies.txt");
    if (!infile) {
        cout << "File could not be opened." << endl;
        return;
    }

    char genre;
    int stock;
    std::string director, title;
    int year;
    // Only for Classics
    string majorActor;
    int releaseMonth;

    while (infile >> genre) {  // Read the first character (genre)
        infile.ignore(1, ' '); // to ignore comma and space

        infile >> stock; // Read stock
        infile.ignore(1, ' ');

        getline(infile, director, ','); // Read director
        infile.ignore(1, ' ');

        getline(infile, title, ',');   // Read title
        infile.ignore(1, ' ');

        // Genre checking
        if (genre != 'C' && genre != 'D' && genre != 'F') {
            std::cerr << "ERROR: " << genre << " Invalid Genre. Try Again." << std::endl;
            infile.ignore(numeric_limits<streamsize>::max(), '\n'); // Skip the rest of the line
            continue;
        }

        // Classics
        // includes special cases
        if (genre == 'C') {
            infile >> majorActor; // First name of major actor
            std::string lastName;
            infile >> lastName;   // Last name of major actor
            majorActor += " " + lastName;

            infile >> releaseMonth >> year;

            // Media* movie = new Classic(genre, stock, director, title, majorActor, month, year);
            // mediaList[title] = movie;
        }


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
            it->second->borrowMovie();  // decrease stock for the borrowed item
            cout << "Successfully borrowed: " << title << std::endl;
        } else {
            cout << "Borrow Transaction Failed -- Not enough in the Stock" << endl;
        }
    } else {
        cout << "Borrow Transaction Failed -- Movie does not Exist in the Inventory" << endl;
    }

}

void Inventory::returnItem(const std::string& title) {
    auto it = mediaList.find(title);
    if (it != mediaList.end()) {
        it->second->returnMovie();
        cout << "Successfully returned: " << title << std::endl;
    } else {
        cout << "Return Transaction Failed -- Movie does not Exist in the Inventory" << endl;
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

