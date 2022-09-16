/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab Quiz 03

Array Manipulation
Write a program that initializes an array of 10 integers.
Use a for loop to initialize the values from 1-10.
Print each number from the array on a seperate line.

Do not use {} to initialize the array.
*/

#include <iostream>
using namespace std;

int main() {
    int arr[10];

    for(int i = 1; i <= 10; i++) {
        arr[i] = i;
        cout << arr[i] << endl;
    }
    
    return 0;
}