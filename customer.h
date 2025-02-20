
#include <string>
#include <iostream>
#include <vector>
#include "transaction.h"
/*
 *
3333 Witch Wicked
8888 Pig Porky
4444 Moose Bullwinkle
9999 Duck Daffy
6666 Donkey Darrell
7777 Spider Sammy
1111 Mouse Mickey
1000 Mouse Minnie
9000 Lizard Larry
8000 Wacky Wally
5000 Frog Freddie
2000 Duck Donald

 */

#ifndef MY_EXECUTABLE_CUSTOMER_H
#define MY_EXECUTABLE_CUSTOMER_H

using namespace std;

class Customer {
private:
    int customerID;
    string firstName;
    string lastName;
    Transaction* startTransaction; // to store history
    Customer* nextCustomer;

public:
    Customer();
    Customer(int customerID, const string& firstName, const string& lastName);
    // todo virtual?
    ~Customer();

    int getCustomerID() const;
    Transaction* getStartTransaction();
    string getFullName();
    string getFirst();
    string getLast();

    Customer* getNextCustomer();
    void addNewCustomer(Customer* customer);
    void addTransaction(Transaction* transaction); // add new transaction
    void displayHistory() const; // to display full transaction history


};




#endif //MY_EXECUTABLE_CUSTOMER_H
