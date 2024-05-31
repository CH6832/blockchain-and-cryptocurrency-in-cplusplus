#include "blockchain.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <openssl/sha.h>

using namespace std;

/**
 * @brief Class representing a block in the blockchain.
 */
class Block {
public:
    int index;
    string previousHash;
    string hash;
    string transactions;
    time_t timestamp;
    int nonce;

    /**
     * @brief Constructor for Block class.
     * @param idx Index of the block.
     * @param prevHash Hash of the previous block.
     * @param txs Transactions in the block.
     */
    Block(int idx, string prevHash, string txs) : index(idx), previousHash(prevHash), transactions(txs) {
        timestamp = time(nullptr);
        nonce = 0;
        hash = calculateHash();
    }

    /**
     * @brief Calculates the hash of the block.
     * @return Hash of the block.
     */
    string calculateHash() const {
        stringstream ss;
        ss << index << previousHash << transactions << timestamp << nonce;
        return sha256(ss.str());
    }

    /**
     * @brief Mines the block.
     * @param difficulty Difficulty level for mining.
     */
    void mineBlock(int difficulty) {
        string target(difficulty, '0');
        while (hash.substr(0, difficulty) != target) {
            nonce++;
            hash = calculateHash();
        }
    }

    /**
     * @brief Computes SHA-256 hash of a string.
     * @param str Input string.
     * @return SHA-256 hash of the string.
     */
    static string sha256(const string str) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, str.c_str(), str.size());
        SHA256_Final(hash, &sha256);
        stringstream ss;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            ss << hex << setw(2) << setfill('0') << (int)hash[i];
        }
        return ss.str();
    }
};

/**
 * @brief Class representing the blockchain.
 */
class Blockchain {
public:
    /**
     * @brief Constructor for Blockchain class.
     */
    Blockchain() {
        chain.emplace_back(Block(0, "0", "Genesis Block"));
        difficulty = 4;
    }

    /**
     * @brief Adds a new block to the blockchain.
     * @param newBlock Block to be added.
     */
    void addBlock(Block newBlock) {
        newBlock.previousHash = getLatestBlock().hash;
        newBlock.mineBlock(difficulty);
        chain.push_back(newBlock);
    }

    /**
     * @brief Validates the blockchain.
     * @return True if the blockchain is valid, false otherwise.
     */
    bool isChainValid() const {
        for (size_t i = 1; i < chain.size(); i++) {
            const Block& currentBlock = chain[i];
            const Block& previousBlock = chain[i - 1];

            if (currentBlock.hash != currentBlock.calculateHash())
                return false;

            if (currentBlock.previousHash != previousBlock.hash)
                return false;
        }
        return true;
    }

    /**
     * @brief Gets the latest block in the blockchain.
     * @return Reference to the latest block.
     */
    const Block& getLatestBlock() const {
        return chain.back();
    }

    /**
     * @brief Prints the blockchain.
     */
    void printChain() const {
        for (const auto& block : chain) {
            cout << "Block #" << block.index << " [previousHash: " << block.previousHash
                << ", hash: " << block.hash << ", transactions: " << block.transactions << "]" << endl;
        }
    }

private:
    vector<Block> chain;
    int difficulty;
};
