#include "transaction.h"
#include <iostream>
using namespace std;

// default constructor
Transaction::Transaction() {
    type = ' ';
    customerID = 0000;
    movieTitle = " ";
}

// param constructor
Transaction::Transaction(char type, int customerID, string movieTitle)
        : type(type), customerID(customerID), movieTitle(movieTitle) {

}

// destructor
Transaction::~Transaction() {

}

// Can be B or R
string Transaction::getType() {

}

Transaction* Transaction::getNextTransaction(){

}


void Transaction::setLastTransaction(Transaction* transaction){

}



