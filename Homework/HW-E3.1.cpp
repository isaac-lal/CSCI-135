/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Homework E3.1

Write a program that reads an integer 
and prints whether it is negative, zero, or positive.
*/

#include <iostream>
using namespace std;

int main() {
    int num;

    cout << "Please enter an integer: " << endl;
    cin >> num;

    if(num > 0) {
        cout << "Positive" << endl;
    } else if(num < 0) {
        cout << "Negative" << endl;
    } else {
        cout << "Zero" << endl;
    }

    return 0;
}