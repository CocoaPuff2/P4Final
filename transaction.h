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
    Transaction(char type, int customerID, string movieTitle);
    void display() const;

};

#endif //MY_EXECUTABLE_TRANSACTION_H
