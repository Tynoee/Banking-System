#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
private:
    int accountId;
    std::string type;
    double amount;

public:
    Transaction(int accountId, const std::string &type, double amount);
    void display() const;
};

#endif
