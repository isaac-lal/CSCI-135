/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab Quiz 08

Brackets

Define a function unbalanced_brackets that takes in a 
string and returns the number of unbalanced brackets. 
In other words, returns the difference of open and closed curly brackets.

int unbalanced_brackets(string input);
*/

#include <iostream>
#include <string>
using namespace std;

int unbalanced_brackets(string input) {
    int count = 0;

    for(int i = 0; i < input.length(); i++) {
        if(input[i] == '{') {
            count++;
        } else if(input[i] == '}') {
            count --;
        }
    }

    return count;
}

int main() {
    string input;

    cout << "Enter brackets: ";
    cin >> input;

    cout << unbalanced_brackets(input);
}