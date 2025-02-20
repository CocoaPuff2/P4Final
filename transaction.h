#include <string>
using namespace std;


#ifndef MY_EXECUTABLE_TRANSACTION_H
#define MY_EXECUTABLE_TRANSACTION_H

// track borrow/return actions.
class Transaction {
private:
    char type;         // 'B' --> Borrow, 'R' --> Return
    int customerID;
    string movieTitle;

public:
    Transaction();
    Transaction(char type, int customerID, string movieTitle);
    // NOTE: destructors should "ALWAYS" be virtual! :)
    virtual ~Transaction();
    // NOTE: This is a virtual function, therefore an abstract class
    virtual void printTransaction() = 0;

    // void display() const;
    string getType(); // Can be B or R
    Transaction* getNextTransaction();
    void setLastTransaction(Transaction* transaction);

};

#endif //MY_EXECUTABLE_TRANSACTION_H
