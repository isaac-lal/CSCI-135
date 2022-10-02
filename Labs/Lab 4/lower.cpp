/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 4D

Write a program lower.cpp that prints the bottom-left half of a square, given the side length.

Example:
Input side length: 6

Shape:
*
**
***
****
*****
******
*/

#include <iostream>
using namespace std;

int main() {
    int size;

    // Asks the user to input the size
    cout << "Input side length: ";
    cin >> size;

    cout << "\nShape: " << endl;
    
    // Runs col for-loop for every value of row for-loop 
    for(int row = 0; row < size; row++) {
        for(int col = 0; col < size; col++) {
            if(row >= col) { // if row is greater or equal to col
                cout << "*"; // Repeats until inputs are done
            } else {
                cout << " ";
            }
        }

        cout << endl;
    }

    return 0;
}