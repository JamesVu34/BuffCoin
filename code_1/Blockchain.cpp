#include<iostream>
#include <sstream>

#include "Transaction.hpp"
#include "Block.hpp"
#include "Blockchain.hpp"
#include<vector>

using namespace std;

Blockchain::Blockchain() {
    Transaction genesis("BFC","BFC",0);
    pending.push_back(genesis);

    Block gBlock(pending, time(nullptr), "In the beginning..");
    chain.push_back(gBlock);

    Transaction freeMoney("BFC","make money by mining",0);
    pending.push_back(freeMoney);

    difficulty = 4;
    miningReward = 10;
}

Block Blockchain::getLatestBlock() { 
    return chain.back();
}

void Blockchain::addTransaction(string src, string dst, int coins) {
    // if it is BFC then allow transaction
    if (src == "BFC") {
        Transaction newTrans = Transaction(src, dst, coins);
        pending.push_back(newTrans);
    }
    // if it is from one user to another check balance of src
    else if (getBalanceOfAddress(src) > coins) {
        Transaction newTrans = Transaction(src, dst, coins);
        pending.push_back(newTrans);
        cout << src << " has sent " << dst << " " << coins << " buffCuoins." << endl;
    }
    else {
        cout << "Error to proccess transaction. Not enough coins in account." << endl;
        cout << "Balance: " << getBalanceOfAddress(src) << endl;
        cout << "Please mine pending transactions to receive coins." << endl;
    }
}

bool Blockchain::isChainValid() { 
    // traverse block chain from second block
    for (int i = 1; i < chain.size(); i++) {
        string previous = chain[i-1].calculateHash();
        string myHash = "";
        string zeros = "";

        // mine block to get nonce values for each 
        chain[i].mineBlock(difficulty);
        
        // checking if previous hash matches previousHash of current Block
        if (chain[i].calculateHash() != previous) {
            return false;
        }

        myHash = chain[i].calculateHash();

        // creating a zeros string
        for (int j = 0; j < difficulty; j++) {
            zeros += "0";
        }

        // if zeros string doesnt match hash then return false
        if (myHash.substr(0, difficulty) != zeros) {
            return false;
        }

    }
    return true;
}

bool Blockchain::minePendingTransactions(string minerAddress) {
    vector<Transaction> pend = pending;
    // creating new Block
    Block newBlock(pend, time(NULL), getLatestBlock().calculateHash());

    newBlock.mineBlock(difficulty);

    // clearing transaction vector and pushing back new block onto chain
    pend.clear();
    chain.push_back(newBlock);

    addTransaction("BFC", minerAddress, miningReward);

    return true;
}

int Blockchain::getBalanceOfAddress(string address) {
    int paid = 0;
    int receive = 0;

    // traverse transaction vector to find address
    for (int i = 0; i < pending.size(); i++) {
        if (pending[i].getSender() == address) {
            paid += pending[i].getAmount();
        }
        if (pending[i].getReceiver() == address) {
            receive += pending[i].getAmount();
        }
    }

    return receive - paid;
}

void Blockchain::prettyPrint() {
    cout << "Format of Print: (Sender, Receiver, Amount)" << endl;
    for (int j = 0; j < pending.size(); j++) {
        cout << pending[j].toString() << endl;
    }
}

void Blockchain::printTransInfo(string address) {
    int receive, sent = 0;

    for (int i = 0; i < pending.size(); i++) {
        if (pending[i].getSender() == address) {
            sent += pending[i].getAmount();
        }
        if (pending[i].getReceiver() == address) {
            receive += pending[i].getAmount();
        }
    }

    cout << address << " has sent " << sent << " coins." << endl;
    cout << address << " balance: " << getBalanceOfAddress(address) << endl;
}