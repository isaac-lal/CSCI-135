/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Homework E5.6

Write a function

string middle(string str)

that returns a string containing the middle character in str if the length of str is odd,
or the two middle characters if the length is even. For example, middle("middle")
returns "dd".
*/

#include <iostream>
using namespace std;

string middle(string str) {
    int mid;
    string temp;

    if(str.length() % 2 == 0) {
        mid = str.length() / 2;
        cout << str[mid - 1] << str[mid];
    } else {
        mid = str.length() / 2;
        cout << str[mid];
    }

    return temp;
}

int main() {
    string str;

    cout << "Enter a string: ";
    cin >> str;

    middle(str);

    return 0;
}