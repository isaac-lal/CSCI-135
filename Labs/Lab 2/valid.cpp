/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 2A

Write a program valid.cpp, which asks the user to input an integer in the range 0 < n < 100. 
If the number is out of range, the program should keep asking to re-enter until a valid number is input.

After a valid value is obtained, print this number n squared.
*/

#include <iostream>
using namespace std;

int main() {
    int num;

    // asks user to input a num
    cout << "Please input an integer in the range 0 < n < 100: " << endl;
    cin >> num;

    // if num isn't within the range, ask user to input until num is
    while(num <= 0 || num >= 100) {
        cout << "Please re-enter: " << endl;
        cin >> num;
    }

    // if num is within the range, square the number and output it
    if(num > 0 && num < 100) {
        cout << "Number squared is " << num * num << endl;
    }

    return 0;
}