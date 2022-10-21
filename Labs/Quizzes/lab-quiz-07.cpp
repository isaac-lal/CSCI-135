/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab Quiz 07

Strings and Functions

Define the function 'void remove_e(string& sentence).'
Removes all 'e' characters from the original string.
*/

#include <iostream>
using namespace std;

void remove_e(string &sentence) {
    for(int i = 0; i < sentence.length(); i++) {
        if(sentence[i] == 'e') {
            sentence.erase(i, 1);
        }
    }
}