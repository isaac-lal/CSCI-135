/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab Quiz 02

Greater of X or Y: Enter two integers x and y, print out the VALUE
of the bigger number.
*/

#include <iostream>
using namespace std;

int main() {
    int x, y;

    cout << "Please enter the value of x: " << endl;
    cin >> x;
    cout << "Please enter the value of y: " << endl; 
    cin >> y;

    if(x > y) {
        cout << x << endl;
    } else {
        cout << y << endl;
    }

    return 0;
}