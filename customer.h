
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
   vector<Transaction> history; // Stores transaction history

public:
    Customer(int customerID, const string& firstName, const string& lastName);

    int getID() const { return customerID; }

    string getFullName() const { return firstName + " " + lastName; }

    void addTransaction(const Transaction& transaction);
    void displayHistory() const;


};




#endif //MY_EXECUTABLE_CUSTOMER_H
