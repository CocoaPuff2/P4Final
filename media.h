
#ifndef P4FINAL_MEDIA_H
#define P4FINAL_MEDIA_H

#include <string>
#include <iostream>

using namespace std;

/*
 * NOTE;
 Comedy (F) --> By title, then by year.
 Drama (D) --> By director, then by title.
 Classics (C) -->  By release date (month, year), then by major actor.
 */

// base class for all movies
class Media {
protected:
    char genre;  // can be F (funny) , D (drama) , or C (classics) only
    int stock; // amount of items available
    string director;
    string title; // title of media
    int year; // release year

public:
    // genre, stock, director, title (majorActor), (releaseMonth), year
    // C, 10, Victor Fleming, The Wizard of Oz, Judy Garland 7 1939
    // F, 10, Nora Ephron, Sleepless in Seattle, 1993
    Media(char genre, int stock, const string& director, const string& title, int year);
    //D, 10, Barry Levinson, Good Morning Vietnam, 1988
    // Media(char genre, int stock, const string& director, const string& title, int year);
    virtual ~Media() = default; // destructor

    char getGenre() const;
    int getStock() const;
    string getDirector() const;
    string getTitle() const;
    int getYear() const;

    virtual void display() const;

    bool borrowMovie();
    void returnMovie();

};


#endif //P4FINAL_MEDIA_H
