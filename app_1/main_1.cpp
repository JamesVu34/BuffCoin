#include <iostream>
#include <fstream>
#include "../code_1/Blockchain.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    // Blockchain buffCUoin;

    // buffCUoin.prettyPrint(); 
    // cout << "ashutosh mining first block ... " << endl;
    // buffCUoin.minePendingTransactions("ashutosh");
    // buffCUoin.prettyPrint(); 
    
    // cout << "ashutosh paid maciej 2 BFC ... " << endl;
    // buffCUoin.addTransaction("ashutosh","maciej", 2);
    // buffCUoin.prettyPrint();

    // cout << "ashutosh paid asa 1 BFC ... " << endl;
    // buffCUoin.addTransaction("ashutosh","asa", 1);
    // cout << "asa mining second block ... " << endl;
    // buffCUoin.minePendingTransactions("asa");
    // buffCUoin.prettyPrint(); 
    
    // cout << "asa paid ashutosh 1 BFC ... " << endl;
    // buffCUoin.addTransaction("asa","ashutosh", 1);    
    // cout << "ashutosh paid maciej 2 BFC ... " << endl;
    // buffCUoin.addTransaction("asa","maciej", 2);
    
    // cout << "maciej mining third block ... " << endl;
    // buffCUoin.minePendingTransactions("maciej");
    // buffCUoin.prettyPrint(); 
    
    // cout << "ashutosh mining fourth block ... " << endl;
    // buffCUoin.minePendingTransactions("ashutosh");
    // buffCUoin.prettyPrint();

    /* PROGRAM STARTS HERE */
    // variables
    string name = "";
    bool quit = false;
    int option = 0;
    string input = "";
    Blockchain buffCUoin;

    // ask user for name and have them input
    cout << "Please enter your name to start: " << endl;
    getline(cin, name);

    cout << "Hello, " << name << "!" << endl;

    while (!quit) {
        // menu
        cout << "=====MAIN MENU=====" << endl;
        cout << "1. Add a Transaction" << endl;
        cout << "2. Mine a Pending Transaction" << endl;
        cout << "3. View Transactions" << endl;
        cout << "4. View Transaction Information" << endl;
        cout << "5. Quit" << endl;

        // get input
        getline(cin, input);
        option = stoi(input);

        // use switch 
        switch (option) {
            case 1: // add transaction
            {
                string sender, receiver, coins = "";
                int amount = 0;

                // ask and have user input sender, receiver, and amount
                cout << "Please enter the sender address: " << endl;
                getline(cin, sender);
                cout << "Please enter the receiver address: " << endl;
                getline(cin, receiver);
                cout << "Please enter the amount you wish to send: " << endl;
                getline(cin, coins);
                amount = stoi(coins);

                buffCUoin.addTransaction(sender, receiver, amount);

                break;
            }

            case 2: // mine transaction
            {
                string address = "";
                
                cout << "Please enter address that you wish to mine from: " << endl;
                getline(cin, address);
                
                if (buffCUoin.minePendingTransactions(address) == false) {
                    cout << "Chain is not valid." << endl;
                }
                else {
                    cout << "Mined Successfully!" << endl;
                    cout << "Balance of " << address << ": " << buffCUoin.getBalanceOfAddress(address) << endl; 
                }

                break;
            }
            case 3: // view transactions
            {
                buffCUoin.prettyPrint();
                break;
            }

            case 4: // view transaction info
            {
                break;
            }

            case 5: // quit
            {
                cout << "Goodbye!" << endl;
                quit = true;
                break;
            }

            default: 
            {
                cout << "Invalid option. Please enter a number 1-5." << endl;
                break;
            }
        }
    }

    return 0;
}