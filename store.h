#ifndef MY_EXECUTABLE_STORE_H
#define MY_EXECUTABLE_STORE_H

#include <iostream>
#include <string>
#include "customer.h"
#include "media.h"

using namespace std;

class Store {
private:
    // Hash table, stores customers, indexed by customerID.
    Customer* hashTable[10];

    // Pointers for  respective LL headers for different movie genres.
    Media *comedy;
    Media *drama;
    Media *classic;

public:
    // Default constructor, initializes the hash table and media pointers.
    Store();

    // Destructor, deallocates memory
    ~Store();

    // Helper method, clear media linked list
    void clearMedia(Media* media);

    // Methods, read data from input streams (for customers and movies)
    void readMovie(ifstream& file);  // Read movie data from file stream (data4movies.txt)
    void readCustomers(ifstream& file);  // Read customer data from file stream (data4customers.txt)
    void readCommands(ifstream& file);  // Read commands from file stream (data4commands.txt)

    // Methods, borrowing movies
    bool borrowComedyMovie(string movieName);  // Borrow comedy movie
    bool borrowDramaMovie(string movieName);  // Borrow drama movie
    // Borrows classic movie based on the major actor's name.
    bool borrowClassicsMovie(string firstName, string lastName);

    // Methods, returning movies
    bool returnComedyMovie(string movieName);  // Return comedy movie.
    bool returnDramaMovie(string movieName);  // Return  drama movie.
    // Return classic movie based on the major actor's name.
    bool returnClassicsMovie(string firstName, string lastName);

    // Customer, Command, and Movie methods.
    void hashTableAdd();  // Add new customer to hash table.
    Customer* hashTableFind(int customerID);  // Find customer in hash table, use customerID.

    // Media factory methods for creating movies based on input file data.
    // Creates a movie based on given genre (Comedy, Drama, or Classics).
    Media* factoryMedia(ifstream& file, string genre);
    // todo: do we need?
    void sortMedia(Media* media);
    // Process when a specific movie is created (based on genre, stock, and title)
    void processingFactory(ifstream& file, string genre, int stock, string title);

};

#endif //MY_EXECUTABLE_STORE_H
