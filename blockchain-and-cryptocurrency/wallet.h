#ifndef WALLET_H
#define WALLET_H

#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <string>
#include <vector>

class Wallet {
public:
    Wallet();
    std::string signTransaction(const std::string& txHash) const;
    bool verifyTransaction(const std::string& txHash, const std::string& signature) const;

private:
    void generateKeys();
    std::vector<unsigned char> privateKey;
    std::vector<unsigned char> publicKey;
};

#endif // WALLET_H
