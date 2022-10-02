/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 4E

Write a program upper.cpp that prints the top-right half of a square, given the side length.

Example:
Input side length: 5

Shape:
*****
 ****
  ***
   **
    *
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
    for(int row = size; row > 0; row--) { // reverse the logic compared to lower
        for(int col = size; col > 0; col--) {
            if(row >= col) { // Repeats until inputs are done
                cout << "*";
            } else {
                cout << " ";
            }
        }

        cout << endl;
    }

    return 0;
}