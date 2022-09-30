/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 4B

Write a program checkerboard.cpp that asks the user to input width 
and height and prints a rectangular checkerboard of the requested size 
using asterisks and spaces (alternating).
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
        if(row % 2 == 0) { // condition to add a space in every other row for col
            for(int col = 0; col < width; col++) {
                if(col % 2 != 0) {
                    cout << " ";
                } else {
                    cout << "*";
                }
            }
        } else { // standard, print * on first col
            for(int col = 0; col < width; col++) {
                if(col % 2 != 0) {
                    cout << "*"; // reverse the other
                } else {
                    cout << " ";
                }
            }
        }

        cout << endl;
    }

    return 0;
}