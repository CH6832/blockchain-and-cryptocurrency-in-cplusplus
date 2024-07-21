#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <openssl/sha.h>
#include "Block.h"

using namespace std;

Block::Block(int idx, std::string prevHash, std::string txs)
    : index(idx), previousHash(prevHash), transactions(txs), timestamp(time(nullptr)), nonce(0) {
    hash = calculateHash();
}

std::string Block::calculateHash() const {
    std::stringstream ss;
    ss << index << previousHash << timestamp << transactions << nonce;
    return sha256(ss.str());
}

void Block::mineBlock(int difficulty) {
    std::string target(difficulty, '0');
    while (hash.substr(0, difficulty) != target) {
        ++nonce;
        hash = calculateHash();
    }
    std::cout << "Block mined: " << hash << std::endl;
}

std::string Block::sha256(const std::string str) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);

    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    }
    return ss.str();
}