#include "transactionforcomedy.h"
#include "transaction.h"

using namespace std;

TransactionForComedy::TransactionForComedy(char newType, char newMediaType, string newTitle, int newYear) {
    type = newType;
    mediaType = newMediaType; // only accepts D for DVD
    title = newTitle;
    year = newYear;

}

TransactionForComedy::~TransactionForComedy() {
    // todo
}


void TransactionForComedy::printTransaction() {
    cout << type << " " << mediaType << " F " << title << ", " << year << endl;
}


// getters
string TransactionForComedy::getTitle() {
    return title;
}
int TransactionForComedy::getYear() {
    return year;
}