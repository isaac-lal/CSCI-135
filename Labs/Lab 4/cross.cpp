/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 4C

Write a program cross.cpp that asks the user to input 
the shape size, and prints a diagonal cross of that dimension.

Example:
Input size: 8

Shape:
*      *
 *    *
  *  *
   **
   **
  *  *
 *    *
*      *
*/

#include <iostream>
using namespace std;

int main() {
    int size;

    // Asks the user to input the size
    cout << "Input size: ";
    cin >> size;

    cout << "\nShape: " << endl;
    
    // Runs col for-loop for every value of row for-loop 
    for(int row = 1; row <= size; row++) { // row = 1 to include the first *, 
                                           // until the inputted size 

        for(int col = 1; col <= size; col++) {

            // * when row is same value as col OR current col = size + 1 - current row 
            // done to reverse the order
            if(row == col || col == (size + 1 - row)) { 
                cout << "*"; // Repeats until inputs are done
            } else {
                cout << " "; 
            }
        }

        cout << endl;
    }

    return 0;
}