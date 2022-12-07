/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 3, Task 2: Starting an Account
*/

#include <iostream>
#include <string>
#include "Bank.hpp"
#include "Account.hpp"

Bank::Bank() {
    exist = 0;
}

std::string Bank::createAccount(std::string firstName, std::string lastName, std::string pin) {
    if(exist < 200) {
        Accounts[exist].setFirstName(firstName);
        Accounts[exist].setLastName(lastName);
        Accounts[exist].setPin(pin);

        exist++;

        return Accounts[exist - 1].getAccountNumber();
    } else {
        return "-1";
    }
}

bool Bank::removeAccount(std::string remove) {
    for(int i = 0; i < exist; i++) {
        if(Accounts[i].getAccountNumber() == remove) {
            for(int j = i; j < exist - 1; j++) {
                Accounts[j] = Accounts[j + 1];
            }

            exist--;

            return true;
        }
    }

    return false;
}

bool Bank::withdraw(int moneyAmount, std::string accountNumber, std::string pin) {
    for(int i = 0; i < exist; i++) {
        if(Accounts[i].getAccountNumber() == accountNumber) {
            if(Accounts[i].getPin() == pin) {
                if(Accounts[i].getBalance() >= moneyAmount) {
                    Accounts[i].transaction(-moneyAmount);

                    return true;
                }
            }
        }
    }
    
    return false;
}

bool Bank::deposit(int moneyAmount, std::string accountNumber, std::string pin) {
    for(int i = 0; i < exist; i++) {
        if(Accounts[i].getAccountNumber() == accountNumber) {
            if(Accounts[i].getPin() == pin) {
                Accounts[i].transaction(moneyAmount);

                return true;
            }
        }
    }

    return false;
}

int Bank::getAccountBalance(std::string accountNumber, std::string pin) {
    for(int i = 0; i < exist; i++) {
        if(Accounts[i].getAccountNumber() == accountNumber) {
            if(Accounts[i].getPin() == pin) {
                return Accounts[i].getBalance();
            }
        }
    }
    
    return -1;
}