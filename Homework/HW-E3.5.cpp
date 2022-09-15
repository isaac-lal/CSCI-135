/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Homework E3.5

Increasing, Decreasing or Neither

Write a program that reads three numbers and prints 
“increasing” if they are in increasing order, 
“decreasing” if they are in decreasing order, 
and “neither” other-wise. Here, “increasing” means “strictly increasing”, 
with each value larger than its predecessor. The sequence 3 4 4 would not be considered increasing.
*/

#include <iostream>
using namespace std;

int main() {
    int num1, num2, num3;

    cout << "Please enter first number: " << endl;
    cin >> num1;
    cout << "Please enter second number: " << endl;
    cin >> num2;
    cout << "Please enter third number: " << endl;
    cin >> num3;

    if(num2 > num1 && num3 > num2) {
        cout << "Increasing" << endl;
    } else if(num2 < num1 && num3 < num2) {
        cout << "Decreasing" << endl;
    } else {
        cout << "Neither" << endl;
    }

    return 0;
}