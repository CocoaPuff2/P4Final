#include <iostream>
#include "transaction.h"
#include "transactionsforclassics.h"

using namespace std;

TransactionForClassics::TransactionForClassics(char newType, char newMediaType, int newMonth, int newYear,
                                               string newActorFirstName, string newActorLastName) {
    type = newType;
    mediaType = newMediaType;
    month = newMonth;
    year = newYear;
    actorFirstName = newActorFirstName;
    actorLastName = newActorLastName;
}

TransactionForClassics::~TransactionForClassics() {
    // todo
}

void TransactionForClassics::printTransaction() {
    cout << type << " " << mediaType << " C  " << month << " " << year << " "
    << actorFirstName << " " << actorLastName << endl;
}

// getters
int TransactionForClassics::getYear() {
    return year;
}

int TransactionForClassics::getMonth() {
    return month;
}

string TransactionForClassics::getFirstName() {
return actorFirstName;

}

string TransactionForClassics::getLastName() {
return actorLastName;
}