#include <iostream>
#include "store.h"


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

}
void Store::readCustomers(ifstream& file) {

}
void Store::readCommands(ifstream& file) {

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
