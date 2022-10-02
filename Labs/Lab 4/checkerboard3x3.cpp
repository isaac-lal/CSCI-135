/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 4F

Write a program checkerboard3x3.cpp that asks the user to input width and height and prints a checkerboard of 3-by-3 squares. (It should work even if the input dimensions are not a multiple of three.)

Example 1:
Input width: 16
Input height: 11

Shape:
***   ***   ***
***   ***   ***
***   ***   ***
   ***   ***   *
   ***   ***   *
   ***   ***   *
***   ***   ***
***   ***   ***
***   ***   ***
   ***   ***   *
   ***   ***   *
Example 2:
Input width: 27
Input height: 27

Shape:
***   ***   ***   ***   ***
***   ***   ***   ***   ***
***   ***   ***   ***   ***
   ***   ***   ***   ***   
   ***   ***   ***   ***   
   ***   ***   ***   ***   
***   ***   ***   ***   ***
***   ***   ***   ***   ***
***   ***   ***   ***   ***
   ***   ***   ***   ***   
   ***   ***   ***   ***   
   ***   ***   ***   ***   
***   ***   ***   ***   ***
***   ***   ***   ***   ***
***   ***   ***   ***   ***
   ***   ***   ***   ***   
   ***   ***   ***   ***   
   ***   ***   ***   ***   
***   ***   ***   ***   ***
***   ***   ***   ***   ***
***   ***   ***   ***   ***
   ***   ***   ***   ***   
   ***   ***   ***   ***   
   ***   ***   ***   ***   
***   ***   ***   ***   ***
***   ***   ***   ***   ***
***   ***   ***   ***   ***
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
    for(int row = 0; row < height; row++) { // condition to add a space in every other row for col
        for(int col = 0; col < width; col++) {
            if((col % 6 == 0 || col % 6 == 1 || col % 6 == 2) && (row % 6 == 3 || row % 6 == 4 || row % 6 == 5)) { // space if remainder is not 0
                cout << " ";
            } else if((row % 6 == 0 || row % 6 == 1 || row % 6 == 2) && (col % 6 == 3 || col % 6 == 4 || col % 6 == 5)) { // space if remainder is not 0
                cout << " ";
            } else {
                cout << "*"; // Repeats until inputs are done
            }
        }

        cout << endl;
    }

    return 0;
}