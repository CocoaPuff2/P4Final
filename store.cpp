#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "store.h"
#include "media.h"
#include "classics.h"
#include "comedy.h"
#include "drama.h"


using namespace std;

Store::Store() {
    // initialize hash table with empty values
    for (int i = 0; i < 10; i++) {
        hashTable[i] = nullptr;
    }

     comedy = nullptr;  // Pointer to the LL of comedy movies.
      drama = nullptr;    // Pointer to the LL of drama movies.
     classic = nullptr;  // Pointer to the ?? of classic movies.
}

Store::~Store() {
    // delete customers
    Customer* deleteCustomer;
    Customer* deleteNextCustomer;

    // delete movies
    clearMedia(comedy);
    clearMedia(drama);
    clearMedia(classic);

    // todo: maybe change 10
    for (int i = 0; i < 10; i++) {
        deleteCustomer = hashTable[i];
        while (deleteCustomer != nullptr) {
            deleteNextCustomer = deleteCustomer->getNextCustomer();
            delete deleteCustomer;
            deleteCustomer = deleteNextCustomer;
        }
        hashTable[i] = nullptr;
    }

}

void Store::clearMedia(Media* media) {
    // to clean out the lists of movies
   if (media == nullptr) {
       return;
   }
   Media *deleteMedia = media;
   Media *deleteNextMedia = deleteMedia->getMedia(); //  get the next movie in LL
   while (deleteMedia != nullptr) {
       delete deleteMedia;
       deleteMedia = deleteNextMedia;
       if (deleteMedia != nullptr) {
           deleteNextMedia = deleteMedia->getMedia();
       }
   }
   media = nullptr; // no more movies in LL
}


// reader methods to read input from files
void Store::readMovie(ifstream& file) {
    string movieGenre;
    // changed to string to make it able to be read by string
    // char mediaType = 'D';

    while (!file.fail()) {
        getline(file, movieGenre, ',');
    }

    // while (std::getline(mediaType, movieGenre, ',')) {
        if (movieGenre == "C" || movieGenre == "D" || movieGenre == "F" ||
            movieGenre == "\nC" || movieGenre == "\nD" || movieGenre == "\nF") {}
        {
            movieGenre = movieGenre.substr(1); // remove newline
        }

        if (movieGenre == "C" || movieGenre == "D" || movieGenre == "F") {
            // Create and sort the movie
            Media* newMovie = factoryMediaMethod(file, movieGenre);
            sortMedia(newMovie, movieGenre);
        } else {
            cout << movieGenre << "Invalid Genre. Try again." << std::endl;
            // skip rest of line
            file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
}


Media* factoryMediaMethod(ifstream& file, string genre) {
    char mediaType = ' ';
    int stock;
    string director, title, stockAsString;

    // read stock
    if (!getline(file, stockAsString, ',') || stockAsString.empty()) return nullptr;
    stock = stoi(stockAsString);

    // read director and title
    if (!getline(file, director, ',') || !getline(file, title, ',')) return nullptr;

    if (genre == "C") {
        string majorActorFirst, majorActorLast;
        int month, year;

        if (!(file >> majorActorFirst >> majorActorLast >> month)) return nullptr;
        if (!getline(file, stockAsString) || stockAsString.empty()) return nullptr;
        year = stoi(stockAsString);

        return new Classics(mediaType, stock, director, title, majorActorFirst, majorActorLast, month, year);
    }  else if (genre == "F") {  // Comedy Movie
        int year;

        if (!getline(file, stockAsString) || stockAsString.empty()) return nullptr;
        year = stoi(stockAsString);

        return new Comedy(mediaType, stock, director, title, year);
    } else if (genre == "D") {  // Drama Movie
        int year;

        if (!getline(file, stockAsString) || stockAsString.empty()) return nullptr;
        year = stoi(stockAsString);

        return new Drama(mediaType, stock, director, title, year);
    } else {
        cout << "Invalid Genre. Try Again. " << genre << endl;
        file.ignore(numeric_limits<streamsize>::max(), '\n');  // Skip invalid line
        return nullptr;
    }

}

void sortMedia(Media* media, string genre) {
    Media* current = nullptr; // pointer to movie before next
    Media* next; // input movie is being compared with this movie .

    if (genre == "C") {
        // if (getClassicLLHead() == nullptr) {
          //  setClassicLLHead(media);
           //  return;
        // }
    }
}


void Store::readCustomers(ifstream& file) {
    int getID;
    string firstName;
    string lastName;

    while (file >> getID >> firstName) {
        std::getline(file >> ws, lastName);

        // customer id 0 - 9999
        if (getID < 0) {
            break;
        }
        if (getID > 9999) {
            std::cout << "The customer ID can't exceed 9999" << std::endl;
            continue;
        }

        hashTableAdd(getID, firstName, lastName);


    }

}

void Store::hashTableAdd(int customerID, string customerFirstName, string customerLastName) {
    // perform open hasing
    int hashLoc = customerID / 1000;
    // create a pointer for the current hash table bucket
    Customer*& bucket = hashTable[hashLoc];

    // if the hash bucket is empty, then add the new customer
    if (bucket = nullptr) {
        bucket = new Customer;
        return;
    }

    // Traverse the inner LL in bucket
    Customer* currentHashBucket = bucket;
    // check if the IDs are all avalible for use
    while (currentHashBucket->getNextCustomer() != nullptr) {
        if (currentHashBucket->getCustomerID() == customerID) {
            std::cout << "ID: " << customerID
                      << " unavalible, new customer cannot be created." << std::endl;
            return;
        }
        currentHashBucket = currentHashBucket->getNextCustomer();
    }

    // check the last node
    if (currentHashBucket->getCustomerID() == customerID) {
        std::cout << "ID: " << customerID
                  << " unavalible, new customer cannot be created." << std::endl;
        return;
    }
    Customer* newCustomer = new Customer(customerID, customerFirstName, customerLastName);
    currentHashBucket->addNewCustomer(newCustomer);

}

void printTotalInventory() {
    cout << "\n";
    //Prints all Comedies
    Media* currentMovie = comedy;
    while (currentMovie != NULL)
    {
        currentMovie->display();
        currentMovie = currentMovie->getMedia();
    }
    //Prints all Dramas
    currentMovie = getDramaHead();
    while (currentMovie != NULL)
    {
        currentMovie->display();
        currentMovie = currentMovie->getMedia();
    }
    //Prints all Classics
    currentMovie = getClassicHead();
    while (currentMovie != NULL)
    {
        currentMovie->display();
        currentMovie = currentMovie->getMedia();
    }
    cout << "\n";
}


void Store::readCommands(ifstream& file) {
    string currentCommand;
    while (file >> currentCommand) {
        // normalize the format
        if (currentCommand.size() == 2 && currentCommand[0] == '\n') {
            currentCommand = currentCommand[1];
        }

        // Handle invalid commands statements
        if (currentCommand != "I" && currentCommand != "H" && currentCommand != "B" && currentCommand != "R") {
            cout << " Invalid Transaction Type. Try Again." << endl;
            file.ignore(numeric_limits<streamsize>::max(), '\n'); // Skip the entire bad input line
            continue;
        }

        // Process inventory display
        if (currentCommand == "I") {
            printTotalInventory();
            continue;
        }

        int customerID;
        file >> customerID;

        // ensure that the customer exists
        Customer* customer = hashTableFind(customerID);
        if (!customer || customerID != customer->getCustomerID()) {
            cout << "ERROR: Borrow Transaction Failed -- Customer " << customerID << " does not exist" << endl;
            file.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        // Display customer history
        if (currentCommand == "H") {
            customer->displayHistory();
            continue;
        }

        // Validate DVD media type
        string mediaType;
        file >> mediaType;
        if (mediaType != "D") {
            cout << "ERROR: " << mediaType << " Invalid Media Type. Try Again." << endl;
            file.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        // Validate movie genre
        string genre;
        file >> genre;
        if (genre != "C" && genre != "D" && genre != "F") {
            cout << "ERROR: " << genre << " Invalid Genre. Try Again." << endl;
            file.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        // Process borrow or return
        if (currentCommand == "B" || currentCommand == "R") {
            processingFactoryMethod(file, currentCommand, customerID, genre);
        }

    }
}

Customer* hashTableFind(int customerID) {
    if (customerID > 9999)
    {
        cout << "Customer ID cannot exceed 9999." << endl;
        return nullptr;
    }

    // Find the hash bucket
    Customer* currentHashBucker = hashTable[customerID / 1000];
}

// borrower methods for movies
bool Store::borrowComedyMovie(string movieName) {

}
bool Store::borrowDramaMovie(string movieName) {

}
bool Store::borrowClassicsMovie(string firstName, string lastName) {

}


// return methods for movies
bool Store::returnComedyMovie(string movieName) {

}
bool Store::returnDramaMovie(string movieName) {

}
bool Store::returnClassicsMovie(string firstName, string lastName) {

}

