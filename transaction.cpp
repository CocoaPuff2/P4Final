#include "transaction.h"
#include <iostream>
using namespace std;

// default constructor
Transaction::Transaction() {
    type = " ";
    nextTransaction = nullptr;
    mediaType = " ";
}

// destructor
Transaction::~Transaction() {
// customer destructor performs deletions for this class
}

string Transaction::getType() { return type; } // Can be B or R
string Transaction::getMediaType() {return mediaType; }
Transaction* Transaction::getNextTransaction(){ return nextTransaction; }
void Transaction::setNextTransaction(Transaction* transaction){ nextTransaction = transaction; }



