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
    cin >> name1, name2, name3;

    cout << "Favorite item #1: " << name1 << endl;
    cout << "Favorite item #2: " << name2 << endl;
    cout << "Favorite item #3: " << name3 << endl;

    return 0;
}