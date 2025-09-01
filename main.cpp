#include "bank.h"
#include <iostream>
#include <string>

int main() {
    Bank bank;
    std::string command;

    std::cout << "=== Banking System Simulator ===\n";
    std::cout << "Commands: create <name> <deposit>, deposit <id> <amount>, withdraw <id> <amount>, list, balance, history, exit\n";

    while (true) {
        std::cout << "> ";
        std::cin >> command;

        if (command == "create") {
            std::string name;
            double deposit;
            std::cin >> name >> deposit;
            bank.createAccount(name, deposit);
        } else if (command == "deposit") {
            int id;
            double amount;
            std::cin >> id >> amount;
            bank.deposit(id, amount);
        } else if (command == "withdraw") {
            int id;
            double amount;
            std::cin >> id >> amount;
            bank.withdraw(id, amount);
        } else if (command == "list") {
            bank.listAccounts();
        } else if (command == "history") {
            bank.listTransactions();
        } else if (command == "balance") {
            int id;
            std::cout << "Enter Account ID: ";
            std::cin >> id;
            bank.checkBalance(id);
        } else if (command == "exit") {
            std::cout << "Exiting Banking System.\n";
            break;
        } else {
            std::cout << "Unknown command. Try again.\n";
        }
    }
    return 0;
}
