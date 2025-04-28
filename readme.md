# BuffCoin Project: A Toy Cryptocurrency (C++)
## Project Overview:
BuffCoin is a C++ project simulating a basic blockchain-based cryptocurrency system. The project focuses on designing and implementing core blockchain functionalities while reinforcing key data structure concepts like linked lists, vectors, and hashing.

## To start:
BuffCUoin Program:
To start enter your name. You will then be prompted to a menu and can choose any option. To get your first 10 coins you must first mine a pending transaction. The options in the main menu are:
1. Add a transaction - Add a transaction between 2 users.

2. Mine a pending transaction - Mine a pending transaction in the transaction vector.

3. View transactions - View all the transactions that occurred during the program.

4. View Transaction Information - Enter an address and see how many coins they sent and what their balance is.

5. Quit - Quit program

run app command:
`g++ main_1.cpp ../code_1/Block.cpp ../code_1/Transaction.cpp ../code_1/Blockchain.cpp ../code_1/sha256.cpp -std=c++17 -o run
./run`