
#ifndef MY_EXECUTABLE_TRANSACTION_H
#define MY_EXECUTABLE_TRANSACTION_H

#include <string>

using namespace std;

// The Transaction class tracks borrow and return actions performed by customers.
class Transaction {
protected:
    // todo char or string?
    // 'B' --> Borrow transaction
    // 'R' --> Return transaction
    // type of transaction
    char type;

    // Pointer to next transaction in LL of transactions
    Transaction* nextTransaction;

    // Type of media involved in the transaction (only 'D' for DVD works currently)
    char mediaType;

public:
    // Default constructor, initializes a new Transaction object.
    Transaction();

    // Virtual destructor, cleanup for no memory leaks
    virtual ~Transaction();

    // Virtual method for printing transaction details.
    // Must be implemented by derived classes to define how the transaction is printed.
    // NOTE: Transaction is an abstract class
    virtual void printTransaction() = 0;

    // Getter for the type of the transaction (can be 'B' or 'R')
    char getType();

    // Getter for the media type (can only be 'D' for DVD)
    char getMediaType();

    // Getter for the pointer to the next transaction in LL
    Transaction* getNextTransaction();

    // Setter to link the current transaction to the next one in LL
    void setNextTransaction(Transaction* transaction);
};

#endif //MY_EXECUTABLE_TRANSACTION_H
