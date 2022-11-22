/* 
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab Quiz 11

Money
Define class Money with public int data members dollars and cents.
*/

#include <iostream>
using namespace std;

class Money {
    public:
        int dollars;
        int cents;
};

Money add_money(Money x, Money y) {
    Money z;

    while (x.cents >= 100) {
        x.cents -= 100;
        x.dollars++;
    }

    x.dollars += y.dollars;
    x.cents += y.cents;

    return(z);
}

int main() {
    Money starting = {100, 00};
    Money withdrawal = {2, 75};

    Money sum = add_money(starting, withdrawal);

    cout << "The sum is $" << sum.dollars << "." << sum.cents;

    return 0;
}