
#ifndef P4FINAL_MEDIA_H
#define P4FINAL_MEDIA_H

#include <string>
#include <iostream>
#include "transaction.h"
#include "customer.h"


using namespace std;

/*
 * NOTE;
For comedy movies: F, Stock, Director, Title, Year it released
For drama movies: D, Stock, Director, Title, Year it released
For classics movies: C, Stock, Director, Title, Major actor Release date
 */

// base class for all movies
class Media {
protected:
    char genre;  //  F (comedy), D (drama), or C (classics) only
    int stock; // amount of copies available
    string director;
    string title; // title of movie
    int year; // release year

    // Uses a LL of media items in the customer to track what each customer has checked out
    // Movies in the LL can be Comedy, Drama, or Classics
    Media* nextMedia; // ptr for the next media/movie item

public:
    Media(); // default constructor
    // genre, stock, director, title, (majorActor) (releaseMonth) year
    // examples:
    // C, 10, Victor Fleming, The Wizard of Oz, Judy Garland 7 1939 (note how no comments for last 3 items)
    // F, 10, Nora Ephron, Sleepless in Seattle, 1993
    //D, 10, Barry Levinson, Good Morning Vietnam, 1988
    Media(char genre, int stock, const string& director, const string& title, int year);
    virtual ~Media();

    // setters
    void setStock(int stock);
    void setMedia(Media *newMedia); // this sets the next movie in the LL for movies

    // getters
    char getGenre() const;
    int getStock() const;
    string getDirector() const;
    string getTitle() const;
    int getYear() const;

    Media* getMedia(); // gets the next movie in the LL for movies

    // for classics only
    virtual int getReleaseMonth();
    virtual string getMajorActorFirstName();
    virtual string getMajorActorLastName();

    // is virtual so that the display works depending on the type of object that calls it
    // NOTE: Media is an ABSTRACT class and it cannot be instantiated
    virtual void display() const = 0;


   //  bool borrowMovie();
   //  void returnMovie();

};


#endif //P4FINAL_MEDIA_H
