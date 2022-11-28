/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab Quiz 11

Money

Define a class, Money, with public int data members
dollars and cents.

Then, define a non member function where you withdraw money from
a balance and return the new balance.

Money withdraw_money(Money balance, Money withdrawal);

- Your balance cannot be negative: If more money is being withdrawn than the balance, 
$0.00 should be the new balance.
- You can assume withdrawal is a positive amount of money. (Can't withdraw negative money)
- Data members should be named exactly as specified.
*/

#include <iostream>
using namespace std;

class Money {
public:
    int dollars, cents;
};

Money withdraw_money(Money balance, Money withdrawal);

int main() {
    Money starting = {100, 00};
    Money withdrawal = {2, 75};
    Money ending = withdraw_money(starting, withdrawal);

    cout << "$" << ending.dollars << "." << ending.cents << endl;
}

Money withdraw_money(Money balance, Money withdrawal) {
    Money ending;

    while(balance.cents <= 0) {
        balance.cents += 100;
        balance.dollars--;
    }

    ending.dollars = balance.dollars - withdrawal.dollars;
    ending.cents = balance.cents - withdrawal.cents;

    return ending;
}