#include "Blockchain.h"
#include <iostream>

Blockchain::Blockchain() {
    difficulty = 4; // Setting a default difficulty level for mining
    chain.push_back(createGenesisBlock());
}

Block Blockchain::createGenesisBlock() const {
    return Block(0, "0", "Genesis Block");
}

void Blockchain::addBlock(Block newBlock) {
    newBlock.previousHash = getLatestBlock().hash;
    newBlock.mineBlock(difficulty);
    chain.push_back(newBlock);
}

bool Blockchain::isChainValid() const {
    for (size_t i = 1; i < chain.size(); ++i) {
        const Block& currentBlock = chain[i];
        const Block& previousBlock = chain[i - 1];

        if (currentBlock.hash != currentBlock.calculateHash()) {
            return false;
        }

        if (currentBlock.previousHash != previousBlock.hash) {
            return false;
        }
    }
    return true;
}

const Block& Blockchain::getLatestBlock() const {
    return chain.back();
}

void Blockchain::printChain() const {
    for (const auto& block : chain) {
        std::cout << "Block " << block.index << " [previousHash : " << block.previousHash
            << ", timestamp : " << block.timestamp << ", transactions : " << block.transactions
            << ", hash : " << block.hash << "]" << std::endl;
    }
}
