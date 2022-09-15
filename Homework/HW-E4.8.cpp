/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Homework E4.8

1 character per line

Write a program that reads a word and prints each character of the word on a sepa-
rate line. For example, if the user provides the input "Harry", the program prints

H
a
r
r
y
*/

#include <iostream>
using namespace std;

int main() {
    string word;

    cout << "Please enter one word: " << endl;
    cin >> word;

    for(int i = 0; i <= word[i]; i++) {
        cout << word[i] << endl;
    }

    return 0;
}