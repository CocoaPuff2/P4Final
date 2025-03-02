#include <iostream>
#include <fstream>
#include "customer.h"
#include "media.h"
#include "transaction.h"
#include "comedy.h"
#include "classics.h"
#include "drama.h"
#include <limits>

using namespace std;

int main() {
    cout<<"\n"<<"Testing Movies"<<endl;
    ifstream infile("data4movies.txt");
    if (!infile) {
        cout << "File could not be opened." << endl;
        return 1;
    }

    // Inventory inventory;  // Inventory object to store movies
    string line;

    while (getline(infile, line)) {

    }



    cout << "Success!" << endl;
    cout << endl;
    return 0;

}
