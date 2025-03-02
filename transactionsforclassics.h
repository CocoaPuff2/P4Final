
#ifndef MY_EXECUTABLE_TRANSACTIONSFORCLASSICS_H
#define MY_EXECUTABLE_TRANSACTIONSFORCLASSICS_H

#include <iostream>
#include "transaction.h"

using namespace std;

class TransactionForClassics : public Transaction {
private:
    int year;
    int month;
    string actorFirstName;
    string actorLastName;

public:
    // type: B or R,
    TransactionForClassics(char type, char mediaType, int month, int year, string actorFirstName, string actorLastName);
    ~TransactionForClassics();
    // is inherently virtual
    void printTransaction();

    // getters
    int getYear();
    int getMonth();
    // for major actors
    string getFirstName();
    string getLastName();
};

#endif //MY_EXECUTABLE_TRANSACTIONSFORCLASSICS_H
