/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 4F

Write a program trapezoid.cpp that prints an upside-down trapezoid of given width and height.

However, if the input height is impossibly large for the given width, then the program should report, Impossible shape!

Example 1:
Input width: 12
Input height: 5

Shape:
************
 **********
  ********
   ******
    ****
Example 2:
Input width: 12
Input height: 7

Impossible shape!
Hint:
You can start with the number of

spaces = 0;
stars = width;
On each line, print that number of spaces followed by that number of stars. After that, the number of spaces gets incremented by 1, while the number of stars gets decremented by 2:

spaces += 1;
stars -= 2;
*/

#include <iostream>
using namespace std;

int main() {
    int width, height;

    // Asks the user to input the width and height
    cout << "Input width: ";
    cin >> width;
    cout << "Input height: ";
    cin >> height;
    
    int stars = width, spaces = 0;

    /*
    Before the if-statement occurs, we need to check
    if the height is valid compared to the width for it to 
    output the right result. This is what the for-loop is for,
    in order to pre-determine the outcome.
    */
    for(int i = 0; i < height; i++) {
        spaces += 1;
        stars -= 2;
    }

    /*
    Checks whether the inputs are valid for the trapezoid shape
    We add 1 to keep the "upper-bound" of odd widths compared to
    heights
    */
    if(stars + 1 < 0) {
        cout << "\nImpossible Shape!";
    } else {
        cout << "\nShape: " << endl;

        // Runs col for-loop for every value of row for-loop 
        for(int row = 0; row < height; row++) {
            for(int col = 0; col < width; col++) {
                if(row >= col + 1 || col >= width - row) {
                    cout << " ";
                } else {
                    cout << "*";
                }
            }

        cout << endl;
        }
    } 

    return 0;
}