
#ifndef MY_EXECUTABLE_TRANSACTIONFORCOMEDY_H
#define MY_EXECUTABLE_TRANSACTIONFORCOMEDY_H

#include <iostream>
#include "transaction.h"

using namespace std;

class TransactionForComedy : public Transaction {
private:
    string title;
    int year;

public:
    // type: B or R,
    TransactionForComedy(char type, char mediaType, string title, int year);
    ~TransactionForComedy();
    // is inherently virtual
    void printTransaction();

    // getters
    string getTitle();
    int getYear();
};

#endif //MY_EXECUTABLE_TRANSACTIONFORCOMEDY_H
