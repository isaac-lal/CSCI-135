/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 2B

Write a program print-interval.cpp that asks the user to input two 
integers L and U (representing the lower and upper limits of the interval), 
and print out all integers in the range L ≤ i < U separated by spaces. 
Notice that we include the lower limit, but exclude the upper limit.
*/

#include <iostream>
using namespace std;

int main() {
    int lower, upper;

    // asks user to input lower and upper number
    cout << "Please enter the lower number: " << endl;
    cin >> lower;
    cout << "Please enter the upper number: " << endl;
    cin >> upper;

    // outputs all numbers in the range of lower to upper EXCEPT for upper limit
    for(int i = lower; i < upper; i++) {
        cout << i << " ";
    }

    return 0;
}