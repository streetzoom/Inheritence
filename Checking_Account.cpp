//
// Created by STZ on 6/15/22.
//
#include "Checking_Account.h"

#include <utility>

Checking_Account::Checking_Account(std::string name, double balance)
    : Account{std::move(name), balance} {
}

bool Checking_Account::withdraw(double amount) {
    amount += withdraw_fee;
    return Account::withdraw(amount);
}

std::ostream &operator<<(std::ostream &os, const Checking_Account &account) {
    os << "[Checking_Account: " << account.name << ": " << account.balance << " ]";
    return os;
}

