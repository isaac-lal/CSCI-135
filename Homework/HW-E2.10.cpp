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
    int gallons, miles, price;

    cout << "Please enter how many gallons are in your car: " << endl;
    cin >> gallons;
    cout << "Please enter how many miles can drive for each gallon: " << endl;
    cin >> miles;
    cout << "Please enter the price of gas for each gallon: " << endl;
    cin >> price;

    double cost = gallons * price / miles;
    double costHundredMiles = cost * 100;

    cout << "The cost per 100 gallons is: " << costHundredMiles << endl;

    return 0;
}