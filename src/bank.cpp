#include "bank.h"
#include <iostream>

Bank::Bank() : nextId(1) {}

void Bank::createAccount(const std::string &owner, double initialDeposit) {
    accounts.emplace_back(nextId, owner, initialDeposit);
    transactions.emplace_back(nextId, "Create", initialDeposit);
    std::cout << "Account created with ID: " << nextId << std::endl;
    nextId++;
}

void Bank::deposit(int accountId, double amount) {
    for (auto &acc : accounts) {
        if (acc.getId() == accountId) {
            acc.deposit(amount);
            transactions.emplace_back(accountId, "Deposit", amount);
            std::cout << "Deposit successful.\n";
            return;
        }
    }
    std::cout << "Account not found.\n";
}

void Bank::withdraw(int accountId, double amount) {
    for (auto &acc : accounts) {
        if (acc.getId() == accountId) {
            if (acc.withdraw(amount)) {
                transactions.emplace_back(accountId, "Withdraw", amount);
                std::cout << "Withdraw successful.\n";
            } else {
                std::cout << "Insufficient balance.\n";
            }
            return;
        }
    }
    std::cout << "Account not found.\n";
}

void Bank::checkBalance(int accountId) {
    bool found = false;
    for (const auto &acc : accounts) {
        if (acc.getId() == accountId) {
            std::cout << "Account ID: " << accountId
                      << " | Balance: $" << acc.getBalance() << std::endl;
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Account not found." << std::endl;
    }
}



void Bank::listAccounts() const {
    for (const auto &acc : accounts) {
        acc.display();
    }
}

void Bank::listTransactions() const {
    for (const auto &t : transactions) {
        t.display();
    }
}
