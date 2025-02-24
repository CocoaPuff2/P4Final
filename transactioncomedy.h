
#ifndef MY_EXECUTABLE_TRANSACTIONCOMEDY_H
#define MY_EXECUTABLE_TRANSACTIONCOMEDY_H

#include <iostream>
#include "transaction.h"

using namespace std;

class TransactionComedy : public Transaction {
private:
    string title;
    int year;

public:
    // type: B or R,
    TransactionComedy(char type, char mediaType, string title, int year);
    ~TransactionComedy();
    // is inherently virtual
    void printTransaction();

    // getters
    string getTitle();
    int getYear();
};

#endif //MY_EXECUTABLE_TRANSACTIONCOMEDY_H
