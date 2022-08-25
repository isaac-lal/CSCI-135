/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 1D

Write a program month.cpp that asks the user to input the year and the month (1-12) 
and prints the number of days in that month (taking into account leap years). 
You may not use switch case or arrays even if you know these language constructs.
*/

#include <iostream>
using namespace std;

int main() {
    int year, month;

    // Asks user to input a year and a month
    cout << "Please enter a year number (1999, 2016, etc.): " << endl;
    cin >> year;
    cout << "Please enter the month from 1-12 (1 = January, 12 = December): " << endl;
    cin >> month;

    // Decides which month has a certain days depending on the number
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        cout << "31 days" << endl;
    } else if(month == 4 || month == 6 || month == 9 || month == 11) {
        cout << "30 days" << endl;
    } else if(month == 2 && (year % 4 == 0 && year % 100 != 0)) {
        cout << "29 days" << endl;
    } else if(month == 2) {
        cout << "28 days" << endl;
    }

    return 0;
}