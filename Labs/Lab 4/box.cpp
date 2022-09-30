/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 4A

Write a program box.cpp that asks the user to input width and height and 
prints a solid rectangular box of the requested size using asterisks.
*/

#include <iostream>
using namespace std;

int main() {
    int width, height;

    // Asks the user to input a width and height
    cout << "Input width: " << endl;
    cin >> width;
    cout << "Input height: " << endl;
    cin >> height;

    // Runs col for-loop for every value of row for-loop 
    // Repeats until finished to create rows and cols
    for(int row = 0; row < height; row++) {
        for(int col = 0; col < width; col++) {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}