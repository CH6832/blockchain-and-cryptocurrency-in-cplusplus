#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
public:
    std::string sender;
    std::string receiver;
    double amount;
    time_t timestamp;
    std::string txHash;

    Transaction(std::string snd, std::string rcv, double amt);

    std::string calculateHash() const;

private:
    std::string sha256(const std::string str);
};

#endif // TRANSACTION_H
