/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab Quiz 01

I love C++: Begin with an introductory comment. Prompt the user for a 
number using "cin >>". Return that number of lines that all say "I love C++"
*/

#include <iostream>
using namespace std;

int main() {
    int num;

    cout << "Please enter a number: ";
    cin >> num;

    for(int i = 0; i < num; i++) {
        cout << "I love C++" << endl;
    }

    return 0;
}