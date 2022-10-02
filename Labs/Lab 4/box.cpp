/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 4A

Write a program box.cpp that asks the user to input width and height and prints a solid rectangular box of the requested size using asterisks.

Also, print a line Shape: between user input and the printed shape (to separate input from output).

Example:
Input width: 7
Input height: 4

Shape:
*******
*******
*******
*******
Hint:
First find how to print one row of stars (print the asterisk character width times followed by end-of-line).
Then, once you know how to print one line of stars, repeat it height times (using a loop).
*/

#include <iostream>
using namespace std;

int main() {
    int width, height;

    // Asks the user to input a width and height
    cout << "Input width: ";
    cin >> width;
    cout << "Input height: ";
    cin >> height;

    cout << "\nShape: " << endl;
    
    // Runs col for-loop for every value of row for-loop 
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            cout << "*"; // Repeats until inputs are done
        }

        cout << endl;
    }

    return 0;
}