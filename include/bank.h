#ifndef BANK_H
#define BANK_H

#include "account.h"
#include "transaction.h"
#include <vector>

class Bank {
private:
    std::vector<Account> accounts;
    std::vector<Transaction> transactions;
    int nextId;

public:
    Bank();
    void createAccount(const std::string &owner, double initialDeposit = 0.0);
    void deposit(int accountId, double amount);
    void withdraw(int accountId, double amount);
    void listAccounts() const;
    void listTransactions() const;
    void checkBalance(int accountId);

};

#endif
