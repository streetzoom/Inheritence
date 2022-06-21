//
// Created by STZ on 6/14/22.
//
#ifndef CHALLENGE_ACCOUNT_H
#define CHALLENGE_ACCOUNT_H
#include <iostream>
#include <string>

class Account {
    friend std::ostream &operator<<(std::ostream &os, const Account &account);
private:
    static constexpr const char *def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;
protected:
    std::string name;
    double balance;
public:
    explicit Account(std::string name = def_name, double balance = def_balance); // Account(std::string name = "Unnamed Account", double balance = 0.0);
    bool deposit(double amount);
    bool withdraw(double amount);
};

#endif //CHALLENGE_ACCOUNT_H
