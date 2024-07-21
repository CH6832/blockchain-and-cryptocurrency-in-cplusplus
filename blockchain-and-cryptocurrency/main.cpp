#include <iostream>
#include <string>
#include <vector>
#include "Blockchain.h"
#include "Wallet.h"

int main() {
    // Create a new blockchain
    Blockchain blockchain;

    // Create a wallet for signing transactions
    Wallet wallet;

    // Add a block with transactions
    std::string transactions1 = "Transaction 1: Alice pays Bob 10 BTC";
    Block block1(1, blockchain.getLatestBlock().hash, transactions1);
    blockchain.addBlock(block1);

    std::cout << "Blockchain after adding block 1:" << std::endl;
    blockchain.printChain();

    // Add another block with transactions
    std::string transactions2 = "Transaction 2: Bob pays Charlie 5 BTC";
    Block block2(2, blockchain.getLatestBlock().hash, transactions2);
    blockchain.addBlock(block2);

    std::cout << "\nBlockchain after adding block 2:" << std::endl;
    blockchain.printChain();

    // Demonstrate signing a transaction
    std::string txHash = block1.calculateHash(); // For demonstration, use the hash of block1
    std::string signature = wallet.signTransaction(txHash);

    std::cout << "\nSignature for transaction hash " << txHash << ":" << std::endl;
    std::cout << signature << std::endl;

    // Verify the signed transaction
    bool isVerified = wallet.verifyTransaction(txHash, signature);

    std::cout << "\nTransaction verification result: " << (isVerified ? "Valid" : "Invalid") << std::endl;

    // Check if blockchain is valid
    bool isChainValid = blockchain.isChainValid();

    std::cout << "\nBlockchain validation result: " << (isChainValid ? "Valid" : "Invalid") << std::endl;

    return 0;
}
