
#ifndef MY_EXECUTABLE_STORE_H
#define MY_EXECUTABLE_STORE_H

#include <iostream>
#include <string>
#include "customer.h"
#include "media.h"

using namespace std;

class Store {
private:
    Customer* hashTable[10]; // to store the customers from input
    // pointers for respective LL headers
    Media *comedy;
    Media *drama;
    Media *classic;

public:
    Store();
    ~Store();
    void clearMedia(Media*); // for media LL cleanup

    // read input
    void readMovie(ifstream&); // read input stream (data4movies.txt)
    void readCustomers(ifstream&); // read input stream (data4customers.txt)
    void readCommands(ifstream&);


    // Methods for Borrow
    bool borrowComedyMovie(string movieName);
    bool borrowDramaMovie(string movieName);
    bool borrowClassicsMovie(string firstName, string lastName);

    // Methods for Return
    bool returnComedyMovie(string movieName);
    bool returnramaMovie(string movieName);
    bool returnClassicsMovie(string firstName, string lastName);

    // Customer, Command, and Movie methods
    void hashTableAdd(); // add customer to the hastable
    Customer* hashTableFind(int customerID); // to find a customer based on the customerID

    // todo: look at the rest
    Media* factoryMovie(ifstream&, string);
    void sortMovies(Media* string);
    void processFactory(ifstream&, string, int, string);


};
#endif //MY_EXECUTABLE_STORE_H
