#include "account.h"
#include <iostream>

Account::Account(int id, const std::string &owner, double balance)
    : id(id), owner(owner), balance(balance) {}

void Account::deposit(double amount) {
    balance += amount;
}

bool Account::withdraw(double amount) {
    if (amount > balance) return false;
    balance -= amount;
    return true;
}

double Account::getBalance() const {
    return balance;
}

int Account::getId() const {
    return id;
}

std::string Account::getOwner() const {
    return owner;
}

void Account::display() const {
    std::cout << "Account[" << id << "] Owner: " << owner
              << " Balance: " << balance << std::endl;
}
