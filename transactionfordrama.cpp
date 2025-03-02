#include <iostream>
#include "transaction.h"
#include "transactionfordrama.h"

using namespace std;

TransactionForDrama::TransactionForDrama(char newType, char newMediaType, string newDirector, string newTitle) {
    type = newType;
    mediaType = newMediaType;
    director = newDirector;
    title = newTitle;
}

TransactionForDrama::~TransactionForDrama() {
     // todo
};

void TransactionForDrama::printTransaction() {
    cout << type<< " " << mediaType << " D " << director << ", " << title << endl;
}

string TransactionForDrama::getDirector() {
    return director;
}

string TransactionForDrama::getTitle() {
    return title;
}