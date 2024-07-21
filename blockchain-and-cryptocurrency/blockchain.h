#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include <ctime>
#include <sstream>
#include <openssl/sha.h>

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
