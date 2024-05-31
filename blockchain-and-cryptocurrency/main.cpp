#include <iostream>
#include "blockchain.h"
#include "transaction.h"
#include "wallet.h"

using namespace std;

void printMenu() {
    cout << "Blockchain Simulation Menu:" << endl;
    cout << "1. Add a new block" << endl;
    cout << "2. Print the blockchain" << endl;
    cout << "3. Validate the blockchain" << endl;
    cout << "4. Create a new transaction" << endl;
    cout << "5. Exit" << endl;
}

int main() {
    Blockchain blockchain;

    Wallet wallet1;
    Wallet wallet2;

    while (true) {
        printMenu();
        int choice;
        cin >> choice;

        if (choice == 1) {
            string transactions;
            cout << "Enter transactions: ";
            cin.ignore();
            getline(cin, transactions);
            Block newBlock(blockchain.getLatestBlock().index + 1, blockchain.getLatestBlock().hash, transactions);
            blockchain.addBlock(newBlock);
            cout << "Block added." << endl;
        }
        else if (choice == 2) {
            blockchain.printChain();
        }
        else if (choice == 3) {
            if (blockchain.isChainValid()) {
                cout << "Blockchain is valid." << endl;
            }
            else {
                cout << "Blockchain is invalid!" << endl;
            }
        }
        else if (choice == 4) {
            string sender, receiver;
            double amount;
            cout << "Enter sender: ";
            cin >> sender;
            cout << "Enter receiver: ";
            cin >> receiver;
            cout << "Enter amount: ";
            cin >> amount;

            Transaction tx(sender, receiver, amount);
            string signature = wallet1.signTransaction(tx.txHash);
            cout << "Transaction signed: " << signature << endl;
            if (wallet2.verifyTransaction(tx.txHash, signature)) {
                cout << "Transaction verified." << endl;
            }
            else {
                cout << "Transaction verification failed." << endl;
            }
        }
        else if (choice == 5) {
            break;
        }
        else {
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
