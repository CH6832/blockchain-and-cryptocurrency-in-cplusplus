#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include <ctime>
#include <sstream>
#include <openssl/sha.h>

/**
 * @brief Class representing a block in the blockchain.
 */
class Block {
public:
    int index;
    std::string previousHash;
    std::string hash;
    std::string transactions;
    time_t timestamp;
    int nonce;

    /**
     * @brief Constructor for Block class.
     * @param idx Index of the block.
     * @param prevHash Hash of the previous block.
     * @param txs Transactions in the block.
     */
    Block(int idx, std::string prevHash, std::string txs);

    /**
     * @brief Calculates the hash of the block.
     * @return Hash of the block.
     */
    std::string calculateHash() const;

    /**
     * @brief Mines the block.
     * @param difficulty Difficulty level for mining.
     */
    void mineBlock(int difficulty);

    /**
     * @brief Computes SHA-256 hash of a string.
     * @param str Input string.
     * @return SHA-256 hash of the string.
     */
    static std::string sha256(const std::string str);
};

/**
 * @brief Class representing the blockchain.
 */
class Blockchain {
public:
    /**
     * @brief Constructor for Blockchain class.
     */
    Blockchain();

    /**
     * @brief Adds a new block to the blockchain.
     * @param newBlock Block to be added.
     */
    void addBlock(Block newBlock);

    /**
     * @brief Validates the blockchain.
     * @return True if the blockchain is valid, false otherwise.
     */
    bool isChainValid() const;

    /**
     * @brief Gets the latest block in the blockchain.
     * @return Reference to the latest block.
     */
    const Block& getLatestBlock() const;

    /**
     * @brief Prints the blockchain.
     */
    void printChain() const;

private:
    std::vector<Block> chain;
    int difficulty;
};

#endif // BLOCKCHAIN_H
