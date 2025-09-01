#include "transaction.h"
#include <iostream>

Transaction::Transaction(int accountId, const std::string &type, double amount)
    : accountId(accountId), type(type), amount(amount) {}

void Transaction::display() const {
    std::cout << "Transaction on Account[" << accountId << "]: "
              << type << " " << amount << std::endl;
}
