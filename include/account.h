#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
private:
    int id;
    std::string owner;
    double balance;

public:
    Account(int id, const std::string &owner, double balance = 0.0);
    void deposit(double amount);
    bool withdraw(double amount);
    double getBalance() const;
    int getId() const;
    std::string getOwner() const;
    void display() const;
};

#endif
