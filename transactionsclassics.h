
#ifndef MY_EXECUTABLE_TRANSACTIONSCLASSICS_H
#define MY_EXECUTABLE_TRANSACTIONSCLASSICS_H

#include <iostream>
#include "transaction.h"

using namespace std;

class TransactionClassics : public Transaction {
private:
    int year;
    int month;
    string actorFirstName;
    string actorLastName;

public:
    // type: B or R,
    TransactionClassics(char type, char mediaType, int month, int year, string actorFirstName, string actorLastName);
    ~TransactionClassics();
    // is inherently virtual
    void printTransaction();

    // getters
    int getYear();
    int getMonth();
    // for major actors
    string getFirstName();
    string getLastName();
};

#endif //MY_EXECUTABLE_TRANSACTIONSCLASSICS_H
