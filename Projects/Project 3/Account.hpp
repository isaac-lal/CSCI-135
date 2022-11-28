/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 3, Task 1: Opening an Account
*/

#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>
#include <string>

class Account {
private:
    // Variables 
    std::string firstName;
    std::string lastName;
    std::string accountNumber;
    std::string pin;
    int accountBalance;

    // private member function
    std::string generateAccountNumber();
public:
    // Constructors
    Account();
    Account(std::string userFirstName, std::string userLastName, std::string pinConfirm);

    // Mutators
    void setFirstName(std::string set);
    void setLastName(std::string set);
    bool setPin(std::string set);

    // Accessors
    std::string getFirstName();
    std::string getLastName();
    std::string getAccountNumber();
    std::string getPin();
    int getBalance();

    // Transactions
    bool transaction(int amount);
};

#endif