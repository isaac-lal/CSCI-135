/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 2C

Write a program edit-array.cpp that creates an array of 10 integers, and provides the user with an interface to edit any of its elements. Specifically, it should work as follows:

1. Create an array myData of 10 integers.
2. Fill all its cells with value 1 (using a for loop).
3. Print all elements of the array on the screen.
4. Ask the user to input the cell index i, and its new value v.
5. If the index i is within the array range (0 ≤ i < 10), update the asked cell, myData[i] = v, and go back to the step 3. Otherwise, if index i is out of range, the program exits.
*/

#include <iostream>
using namespace std;

int main() {
    int myData[10] = {};

    // filling all 10 array values with 1
    for(int i = 0; i < 10; i++) {
        myData[i] = 1;
        cout << myData[i] << " ";
    }

    int index, value;
    
    // as long as index is within 0-9, program will run
    while(index >= 0 && index < 10) {
        // asks user to input an index and value
        cout << "\n\nInput index: " << endl;
        cin >> index;
        cout << "Input value: " << endl;
        cin >> value;

        // output the updated value within index of0-9
        for(int i = 0; i < 10; i++) {
            if(index >= 0 && index < 10) { 
                myData[index] = value;
                cout << myData[i] << " ";
            } 
        }
    }

    // if index is out of range, exit program
    if(index < 0 || index > 9) {
        cout << "Index out of range. Exit" << endl;
    }

    return 0;
}