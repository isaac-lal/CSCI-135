/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 1B

Write a program smaller3.cpp that asks the user to input three integer numbers, 
and prints out the smallest of the three.
*/

#include <iostream>
using namespace std;

int main() {
    int num1, num2, num3;

    // This sequence asks the user to input three numbers
    cout << "Enter the first number: " << endl;
    cin >> num1;
    cout << "Enter the second number: " << endl;
    cin >> num2;
    cout << "Enter the third number: " << endl;
    cin >> num3;

    // These if-statements calculate the smaller of the three numbers inputted
    if(num1 <= num2 && num1 <= num3) {
        cout << "The smaller of the three is " << num1 << endl;
    } else if(num2 <= num1 && num2 <= num3) {
        cout << "The smaller of the three is " << num2 << endl;
    } else {
        cout << "The smaller of the three is " << num3 << endl;
    }

    return 0;
}