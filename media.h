#ifndef P4FINAL_MEDIA_H
#define P4FINAL_MEDIA_H

#include <string>
#include <iostream>
#include "transaction.h"
#include "customer.h"

using namespace std;

/*
 * NOTE:
 * For comedy movies: F, Stock, Director, Title, Year it released
 * For drama movies: D, Stock, Director, Title, Year it released
 * For classics movies: C, Stock, Director, Title, Major actor Release date
 */


class Media {
protected:
    char genre;  // F (comedy), D (drama), or C (classics) only
    int stock;   // Number of available copies of the movie
    string director;  // Director of the movie
    string title;     // Title of the movie
    int year;         // Release year of the movie
    Media* nextMedia; // Pointer to the next media/movie item in a linked list (LL)

public:
    // Default Constructor
    Media();
    // Parametized Constructor
    // Examples:
    // C, 10, Victor Fleming, The Wizard of Oz, Judy Garland 7 1939
    // F, 10, Nora Ephron, Sleepless in Seattle, 1993
    // D, 10, Barry Levinson, Good Morning Vietnam, 1988
    Media(char genre, int stock, const string& director, const string& title, int year);

    // Virtual Destructor
    virtual ~Media();

    // Setters
    void setStock(int stock);  // Set the stock of available copies
    void setMedia(Media* newMedia);  // Set the next media item in the linked list

    // Getters
    char getGenre() const;        // Get the genre of the movie
    int getStock() const;         // Get the stock (number of copies) of the movie
    string getDirector() const;   // Get the director's name
    string getTitle() const;      // Get the title of the movie
    int getYear() const;          // Get the release year of the movie

    Media* getMedia();            // Get the next movie in the linked list

    // Functions specific to classics only
    virtual int getReleaseMonth();   // Get the release month (only for classics)
    virtual string getMajorActorFirstName(); // Get the first name of the major actor (only for classics)
    virtual string getMajorActorLastName();  // Get the last name of the major actor (only for classics)

    // Virtual function for displaying the media details,
    // to be overridden in the subclasses
    virtual void display() const = 0;

    // Additional methods for borrowing and returning movies could be added here
};

#endif //P4FINAL_MEDIA_H
