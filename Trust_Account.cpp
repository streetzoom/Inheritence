//
// Created by STZ on 6/15/22.
//

#include "Trust_Account.h"

#include <utility>

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account{std::move(name), balance, int_rate}, current_withdraw_per_year{0} {
}

// Withdraw - 3 withdraw per year and each of these must be less than 20% of the account balance
bool Trust_Account::withdraw(double amount) {
    if (current_withdraw_per_year >= max_withdraw_per_year || amount > balance * max_withdraw_percent) {
        return false;
    } else {
        ++current_withdraw_per_year;
        return Savings_Account::withdraw(amount);
    }
}

// any deposit of $5000.0 or more will receive a $50.00 bonus deposited to the account
bool Trust_Account::deposit(double amount) {
    if (amount >= bonus_threshold) {
        balance += bonus_reward;
    }
    return Savings_Account::deposit(amount);
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Trust_Account: " << account.name << ": " << account.balance << ", " << account.int_rate
    << "%, withdrawals " << account.current_withdraw_per_year << " ]";
    return os;
}


