#include<iostream>
#include <sstream>


#include "Transaction.hpp"
#include "Block.hpp"
#include "sha256.hpp"

using namespace std;

Block::Block(vector<Transaction> _transactions, time_t _timestamp, string _previousHash) {
    nonce = -1;
    transactions = _transactions;
    previousHash = _previousHash;
    timestamp = _timestamp;
    hash = calculateHash();
}

void Block::setPreviousHash(string _previousHash) {

}

string Block::calculateHash() {
    return sha256(toString());;   
}

void Block::mineBlock(unsigned int difficulty) {
    string myHash = calculateHash();

    // do
    // {
        /* code */
    // } while (myHash.substr(0, difficulty) != ); (find out what to put after !=)
    
    
}

string Block::toString() {
    stringstream toHash; 

    // format for string
    // (nounce, time stamp, previous hash) (all transactions)

    /* Maybe fix nounce value??*/

    toHash << "(" << -1 << ", " << timestamp << ", " << previousHash << ") ";
    for (int i = 0; i < transactions.size(); i++) {
        Transaction t = transactions[i];

        toHash << t.toString();
    }
    
    return toHash.str();
}