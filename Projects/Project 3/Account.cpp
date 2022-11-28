/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 3, Task 1: Opening an Account
*/

#include <iostream>
#include <string>
#include "Account.hpp"

// orivate member function
std::string Account::generateAccountNumber() {
    std::string an_str = "";

    for(int i{0}; i < 8; i++) {
        int temp = rand() % 10;
        an_str += std::to_string(temp);
    }

    return an_str;
}

// Constructors
Account::Account() {
    firstName = "anonymous";
    lastName = "anonymous";
    pin = "0000";
    accountNumber = generateAccountNumber();
    accountBalance = 0;
}

Account::Account(std::string userFirstName, std::string userLastName, std::string pinConfirm) {
    firstName = userFirstName;
    lastName = userLastName;

    if(pinConfirm.length() == 4) {
        pin = pinConfirm;
    } else {
        pin = "0000";
    }

    accountNumber = generateAccountNumber();    
    accountBalance = 0;
}

// Mutators
void Account::setFirstName(std::string set) {
    firstName = set;
}

void Account::setLastName(std::string set) {
    lastName = set;
}

bool Account::setPin(std::string set) {
    if(set.length() == 4) {
        pin = set;

        return true;
    } else {
        return false;
    }
}

// Accessors
std::string Account::getFirstName() {
    return firstName;
}

std::string Account::getLastName() {
    return lastName;
}

std::string Account::getAccountNumber() {
    return accountNumber;
}

std::string Account::getPin() {
    return pin;
}

int Account::getBalance() {
    return accountBalance;
}

// Transactions
bool Account::transaction(int amount) {
    if(accountBalance + amount < 0) {
        return false;
    } else {
        accountBalance += amount;

        return true;
    }
}