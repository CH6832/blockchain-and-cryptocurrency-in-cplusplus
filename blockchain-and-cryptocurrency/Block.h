#ifndef BLOCK_H
#define BLOCK_H

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
