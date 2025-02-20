#include "customer.h"
#include <iostream>

using namespace std;

// default constructor with basic values
Customer::Customer() {
    customerID = 0000;
    firstName = " ";
    lastName = " ";
    nextCustomer = nullptr;
    startTransaction = nullptr;
}

// param constructor
Customer::Customer(int customerID, const string& firstName, const string& lastName)
        : customerID(customerID), firstName(firstName), lastName(lastName) {
    nextCustomer = nullptr;
    startTransaction = nullptr;
}


// destructor
Customer::~Customer() {
    while  (startTransaction) { // if the history of transactions is not already empty
        // todo may need refinement
        Transaction* temp = startTransaction->getNextTransaction();
        delete startTransaction;
        startTransaction = temp;
    }
}

// a setter function to add the next customer
void Customer::addNewCustomer(Customer* customer) {
    nextCustomer = customer;
}

// add new transaction
void Customer::addTransaction(Transaction* transaction){
    if (startTransaction == nullptr) {
        startTransaction = transaction;
        return;
    }
    Transaction* temp = startTransaction;
    // while the next transaction is not the end of the transaction history
    while (temp->getNextTransaction() != nullptr) {
        temp = temp->getNextTransaction(); // move the transaction forward
    }
    // temp is the new last transaction now!
    temp->setLastTransaction(transaction);
}

// to display full transaction history
void Customer::displayHistory() const {
    cout << "History for " << firstName << " " << lastName << ": " << endl;
    if (startTransaction == nullptr) {
        return;
    }

    // print each individual transaction
    Transaction* transaction = startTransaction;
    while (transaction != nullptr) {
        transaction->printTransaction();
        transaction->getNextTransaction();
    }

    cout << endl;

}

// getters
Customer* Customer::getNextCustomer(){
    return nextCustomer;
}

int Customer::getCustomerID() const {
    return customerID;
}

string Customer::getFullName() {
    return firstName + " " + lastName;
}
string Customer::getFirst() {
    return firstName;

}
string Customer::getLast() {
    return lastName;
}

Transaction *Customer::getStartTransaction() {
    return startTransaction;
}

