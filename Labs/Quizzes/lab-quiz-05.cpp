/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab Quiz 05

Rectangle

Print 6 rows, 5 columns, * shape, each line is "****", the last * 
is not followed by space
*/

#include <iostream>
using namespace std;

int main() {
    int rectRow = 6;
    int rectCol = 5;

    for(int row = 0; row < rectRow; row++) {
        for(int col = 0; col < rectCol; col++) {
            cout << "+";
        }

        cout << endl;
    }

    return 0;
}