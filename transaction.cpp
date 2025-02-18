#include "transaction.h"
#include <iostream>
using namespace std;

Transaction::Transaction(char type, int customerID, string movieTitle)
        : type(type), customerID(customerID), movieTitle(movieTitle) {}

void Transaction::display() const {
    cout << "Transaction: " << (type == 'B' ? "Borrow" : "Return")
              << " - Customer ID: " << customerID
              << ", Movie: " << movieTitle << endl;
}

