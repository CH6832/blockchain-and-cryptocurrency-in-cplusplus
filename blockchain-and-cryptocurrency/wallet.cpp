#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <iostream>
#include <sstream>
#include "wallet.h"

Wallet::Wallet() {
    generateKeys();
}

void Wallet::generateKeys() {
    RSA* keypair = RSA_generate_key(2048, RSA_F4, nullptr, nullptr);
    BIO* pri = BIO_new(BIO_s_mem());
    BIO* pub = BIO_new(BIO_s_mem());

    PEM_write_bio_RSAPrivateKey(pri, keypair, nullptr, nullptr, 0, nullptr, nullptr);
    PEM_write_bio_RSAPublicKey(pub, keypair);

    size_t pri_len = BIO_pending(pri);
    size_t pub_len = BIO_pending(pub);

    privateKey.resize(pri_len);
    publicKey.resize(pub_len);

    BIO_read(pri, privateKey.data(), pri_len);
    BIO_read(pub, publicKey.data(), pub_len);

    BIO_free_all(pri);
    BIO_free_all(pub);
    RSA_free(keypair);
}

std::string Wallet::signTransaction(const std::string& txHash) const {
    RSA* rsa = RSA_new();
    BIO* keybio = BIO_new_mem_buf(privateKey.data(), -1);
    PEM_read_bio_RSAPrivateKey(keybio, &rsa, nullptr, nullptr);

    unsigned char signature[256];
    unsigned int signature_len;

    RSA_sign(NID_sha256, reinterpret_cast<const unsigned char*>(txHash.c_str()), txHash.size(), signature, &signature_len, rsa);

    std::stringstream ss;
    for (unsigned int i = 0; i < signature_len; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(signature[i]);
    }

    RSA_free(rsa);
    BIO_free(keybio);

    return ss.str();
}

bool Wallet::verifyTransaction(const std::string& txHash, const std::string& signature) const {
    RSA* rsa = RSA_new();
    BIO* keybio = BIO_new_mem_buf(publicKey.data(), -1);
    PEM_read_bio_RSAPublicKey(keybio, &rsa, nullptr, nullptr);

    std::vector<unsigned char> signature_bytes;
    for (size_t i = 0; i < signature.length(); i += 2) {
        unsigned char byte = std::stoi(signature.substr(i, 2), nullptr, 16);
        signature_bytes.push_back(byte);
    }

    bool result = RSA_verify(NID_sha256, reinterpret_cast<const unsigned char*>(txHash.c_str()), txHash.size(),
        signature_bytes.data(), signature_bytes.size(), rsa);

    RSA_free(rsa);
    BIO_free(keybio);

    return result;
}
