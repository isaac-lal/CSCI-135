/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Homework E1.7

Write a program that prints three items, such as the names of 
your three best friends or favorite movies, on three separate lines.
*/

#include <iostream>
using namespace std;

int main() {
    string name1, name2, name3;

    // Asks user to input their best friend
    cout << "Please enter best friend #1: " << endl;
    cin >> name1;
    cout << "Please enter best friend #2: " << endl;
    cin >> name2;
    cout << "Please enter best friend #3: " << endl;
    cin >> name3;
    
    // Prints out in the terminal the 3 best friends
    cout << name1 << endl;
    cout << name2 << endl;
    cout << name3 << endl;

    return 0;
}