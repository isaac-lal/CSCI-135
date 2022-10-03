/* 
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 5A

Write a program numbers.cpp that defines a function

bool isDivisibleBy(int n, int d);
If n is divisible by d, the function should return true, otherwise return false.

For example:
isDivisibleBy(100, 25) == true
isDivisibleBy(35, 17) == false
The program should also have a main function that tests your code. For example, it can ask the user to input two integer numbers and print Yes if the first number is divisible by the second, otherwise print No.
*/

#include <iostream>
using namespace std;

bool isDivisibleBy(int n, int d);

int main() {
    int divide, divideBy;

    cout << "Enter the number you want to divide: ";
    cin >> divide;
    cout << "Enter the number you want to divide by: ";
    cin >> divideBy;

    if(isDivisibleBy(divide, divideBy) == true) {
        cout << "Yes";
    } else if(isDivisibleBy(divide, divideBy) == false) {
        cout << "No";
    }
}

bool isDivisibleBy(int n, int d) {
    // checks if n is divisible by d 
    if((n % d) == 0) {
        return true;
    } else {
        return false;
    }
}