/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 1A

Write a program smaller.cpp that asks the user to input two integer numbers and prints out the smaller of the two.
*/

#include <iostream>
using namespace std;

int main() {
    int num1, num2;

    // Asks user to input two different numbers
    cout << "Enter the first number: " << endl;
    cin >> num1;
    cout << "Enter the second number: " << endl;
    cin >> num2;

    // Decides which of the two numbers inputted is smaller
    if(num1 < num2) {
        cout << "The smaller of the the two is " << num1 << endl;
    } else {
        cout << "The smaller of the the two is " << num2 << endl;
    }

    return 0;
}