
#ifndef MY_EXECUTABLE_CUSTOMER_H
#define MY_EXECUTABLE_CUSTOMER_H

#include <string>
#include <iostream>
#include <vector>
#include "transaction.h"

using namespace std;

/*
 * The Customer class represents a customer who rents media/movies from the store.
 * It stores essential customer information including ID, full name, and transaction history.
 * The customer can have multiple transactions, this class includes adding new customers,
 * maintaining a LL of customers, and displaying transaction history.
 */

class Customer {
private:
    int customerID;  // Stores unique customer ID
    string firstName;  // First name of customer
    string lastName;  // Last name of customer
    Transaction* startTransaction;  // Head pointer to linked list of transactions for  customer
    Customer* nextCustomer;  // Pointer to the next customer in the linked list

public:
    /*
     * Default constructor,  initializes the customer to default values.
     */
    Customer();

    /*
     * Parameterized constructor that initializes a customer with an ID, first name, and last name.
     * Parameters:
     * customerID Unique ID for the customer.
     * firstName The first name of the customer.
     * lastName The last name of the customer.
     */
    Customer(int customerID, const string& firstName, const string& lastName);

    /*
     * Destructor, cleans up the customer's transaction list
     */
    ~Customer();

    // Getters and Setters

    // Returns unique customer ID.
    int getCustomerID() const;

    // Returns full name of customer (combine first and last names).
    string getFullName();

    // Returns first name of customer.
    string getFirst();

    // Returns last name of customer.
    string getLast();

    // Returns pointer to the head of the customer's transaction LL.
    Transaction* getStartTransaction();

    // Returns the pointer to the next customer in  LL
    Customer* getNextCustomer();

    // Functions to manipulate customer data

    // Adds a new customer to the linked list of customers.
    void addNewCustomer(Customer* customer);

    // Adds a new transaction to the customer's transaction history.
    void addTransaction(Transaction* transaction);

    // Displays the full transaction history for customer.
    void displayHistory() const;

};


#endif //MY_EXECUTABLE_CUSTOMER_H
