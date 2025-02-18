#include "customer.h"
#include <iostream>
using namespace std;

Customer::Customer(int customerID, const string& firstName, const string& lastName)
        : customerID(customerID), firstName(firstName), lastName(lastName) {}

void Customer::addTransaction(const Transaction& transaction) {
    history.push_back(transaction);
}

void Customer::displayHistory() const {
    std::cout << "Transaction history for " << firstName << " " << lastName << ":\n";
    for (const auto& t : history) {
        t.display();
    }
}