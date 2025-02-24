
#ifndef MY_EXECUTABLE_TRANSACTIONDRAMA_H
#define MY_EXECUTABLE_TRANSACTIONDRAMA_H

#include <iostream>
#include "transaction.h"

using namespace std;

class TransactionDrama : public Transaction {
private:
    string title;
    string director;

public:
    // type: B or R,
    TransactionDrama(char type, char mediaType, string director, string title);
    ~TransactionDrama();
    // is inherently virtual
    void printTransaction();

    // getters
    string getDirector();
    string getTitle();
};


#endif //MY_EXECUTABLE_TRANSACTIONDRAMA_H
