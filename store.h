#ifndef MY_EXECUTABLE_STORE_H
#define MY_EXECUTABLE_STORE_H

#include <iostream>
#include <string>
#include "customer.h"
#include "media.h"

using namespace std;

/*
 * Store class represents a movie rental store that manages customers and media inventory.
 * It includes functionality for reading customer and movie data, processing customer
 * transactions, like borrowing and returning movies.
 */
class Store {
    // todo: changed to protected from private
protected:
    /*
     * Hash table for storing customers, indexed by customer ID.
     * The hash table size is fixed at 10 for simplicity.
     */
    // todo: maybe change 10
    Customer* hashTable[10];

    /*
     * Linked list pointers to the head of different movie genre categories.
     * Each pointer represents the first node in a linked list of movies.
     */
    Media *comedy;   // Pointer to the LL of comedy movies.
    Media *drama;    // Pointer to the LL of drama movies.
    Media *classic;  // Pointer to the ?? of classic movies.

public:
    /*
     * Initializes the store by setting up the hash table
     * and media inventory.
     */
    Store();

    /*
     * Cleans up allocated memory for customers and media inventory.
     */
    ~Store();

    /*
     * Helper method that clears a media linked list.
     */
    void clearMedia(Media* media);


    /*
     * Reads movie data from a given input file and populates the media inventory.
     * - Read file line by line.
     * - Parse movie attributes (genre, title, stock, etc.).
     * - Create corresponding media objects and add them to inventory.
     */
    void readMovie(ifstream& file);

    /*
     * Reads customer data from a given input file and adds customers to the hash table.
     * - Read file line by line.
     * - Parse customer ID, first name, and last name.
     * - Create Customer objects and store them in hashTable.
     */
    void readCustomers(ifstream& file);

    /*
     * Reads commands from an input file and processes them (borrow, return, history, etc.).
     * - Read command from file.
     * - Determine action (borrow, return, display history).
     * - Execute corresponding method based on command type.
     */
    void readCommands(ifstream& file);

    /*
     * Attempts to borrow a comedy movie by title.
     * return True if the movie was successfully borrowed, false otherwise.
     */
    bool borrowComedyMovie(string movieName);

    /*
     * Attempts to borrow a drama movie by title.
     * true if successfully borrowed, else false.
     */
    bool borrowDramaMovie(string movieName);

    /*
     * Attempts to borrow a classic movie based on the major actor's name.
     * return true if successfully borrowed, else false.
     */
    bool borrowClassicsMovie(string firstName, string lastName);


    /*
     * Attempts to return a comedy movie by title.
     * return True if the movie was successfully returned, false otherwise.
     */
    bool returnComedyMovie(string movieName);

    /*
     * Attempts to return a drama movie by title.
     * return True if the movie was successfully returned, false otherwise.
     */
    bool returnDramaMovie(string movieName);

    /*
     * Attempts to return a classic movie based on the major actor's name.
     * return True if the movie was successfully returned, false otherwise.
     */
    bool returnClassicsMovie(string firstName, string lastName);


    /*
     * Adds a new customer to the hash table.
     * - Compute hash index from customer ID.
     * - Check for collision and handle if necessary.
     * - Insert customer into hashTable at the computed index.
     */
    void hashTableAdd(int customerID, string customerFirstName, string customerLastName);

    /*
     * Finds and returns a customer based on their customer ID.
     * return Pointer to the Customer object if found, nullptr otherwise.
     */
    Customer* hashTableFind(int customerID);

    /*
     * Factory method for creating Media objects based on input file data.
     * return Pointer to the newly created Media object.
     */
    Media* factoryMediaMethod(ifstream& file, string genre);

    /*
     * Sorts a linked list of Media objects.
     * Note: Sorting method and criteria depend on movie type
     */
    void sortMedia(Media* media, string genre);

    /*
     * Processes a specific movie entry when it is created.
     * - Parse input file for movie attributes.
     * - Validate and process data.
     * - Add movie to the appropriate media linked list.
     */
    void processingFactoryMethod(ifstream& file, string genre, int stock, string title);
    void printTotalInventory();

    // getters for private values
    Media* getComedyHead() const { return comedy; }
    Media* getDramaHead() const { return drama; }
    Media* getClassicHead() const { return classic; }


    // setters for private values
    void setClassicLLHead(Media* media) {
        classic = media;
    }
};

#endif // MY_EXECUTABLE_STORE_H
