/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Homework E2.10

Write a program that asks the user to input
• The number of gallons of gas in the tank
• The fuel efficiency in miles per gallon
• The price of gas per gallon
Then print the cost per 100 miles and how far the car can go with the gas in the tank.
*/

#include <iostream>
using namespace std;

int main() {
    double gallons, miles, price;

    // Asks user to input
    cout << "Please enter the number of gallons of gas in the tank: " << endl;
    cin >> gallons;
    cout << "Please enter the fuel efficiency in miles per gallon: " << endl;
    cin >> miles;
    cout << "Please enter the price of gas per gallon: " << endl;
    cin >> price;

    // variables to calculate costs
    double costHundredMiles = (100 / miles) * price;
    double farHundredMiles = gallons * miles;

    // Outputs in terminal the answer to the program
    cout << "The cost of gas per 100 miles is: " << costHundredMiles << endl;
    cout << "Your car can go " << farHundredMiles << " miles with the amount of gas in the tank" << endl;

    return 0;
}