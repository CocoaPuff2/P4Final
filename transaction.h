#include <string>
using namespace std;


#ifndef MY_EXECUTABLE_TRANSACTION_H
#define MY_EXECUTABLE_TRANSACTION_H

// track borrow/return actions.
class Transaction {
private:
    // todo string or char?
    char type;         // 'B' --> Borrow, 'R' --> Return
    Transaction* nextTransaction;
    // todo string or char?
    char mediaType; // currently only D for DVD

public:
    Transaction();
    // Transaction(char type, int customerID, string movieTitle);
    // NOTE: destructors should "ALWAYS" be virtual! :)
    virtual ~Transaction();
    // NOTE: This is a virtual function, therefore an abstract class
    virtual void printTransaction() = 0;

    char getType(); // Can be B or R
    char getMediaType();
    Transaction* getNextTransaction();
    void setNextTransaction(Transaction* transaction);

};

#endif //MY_EXECUTABLE_TRANSACTION_H
