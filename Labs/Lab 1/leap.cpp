/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 1C

Write a program leap.cpp that asks the user to input an integer representing a year number (1999, 2016, etc.). 
If the input year is a leap year according to the modern Gregorian calendar, it should print Leap year, otherwise, print Common year.
*/

#include <iostream>
using namespace std;

int main() {
    int year;

    // Asks user to input a year
    cout << "Please enter a year number (1999, 2016, etc.): " << endl;
    cin >> year;

    // Decides if the year is a common year or leap year
    if(year % 4 != 0) {
        cout << "Common year";
    } else if(year % 100 != 0) {
        cout << "Leap year";
    } else if(year % 400 != 0) {
        cout << "Common year";
    } else {
        cout << "Leap year";
    }

    return 0;
}