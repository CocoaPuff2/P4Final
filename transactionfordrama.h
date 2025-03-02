
#ifndef MY_EXECUTABLE_TRANSACTIONFORDRAMA_H
#define MY_EXECUTABLE_TRANSACTIONFORDRAMA_H

#include <iostream>
#include "transaction.h"

using namespace std;

class TransactionForDrama : public Transaction {
private:
    string title;
    string director;

public:
    // type: B or R,
    TransactionForDrama(char type, char mediaType, string director, string title);
    ~TransactionForDrama();
    // is inherently virtual
    void printTransaction();

    // getters
    string getDirector();
    string getTitle();
};


#endif //MY_EXECUTABLE_TRANSACTIONFORDRAMA_H
