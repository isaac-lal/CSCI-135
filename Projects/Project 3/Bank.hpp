/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 3, Task 2: Starting an Account
*/

#include <iostream>
#include <string>
#include "Account.hpp"

class Account;

class Bank {
private:
    // Member Variables
    Account Accounts[200];
    int exist;
public:
    // Constructors
    Bank();

    // Account Functions
    std::string createAccount(std::string firstName, std::string lastName, std::string pin);
    bool removeAccount(std::string remove);
    bool withdraw(int moneyAmount, std::string accountNumber, std::string pin); 
    bool deposit(int moneyAmount, std::string accountNumber, std::string pin);
    int getAccountBalance(std::string accountNumber, std::string pin);
};