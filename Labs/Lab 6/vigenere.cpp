/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 6C

Write a program vigenere.cpp. It should contain a function encryptVigenere implementing this cipher:

string encryptVigenere(string plaintext, string keyword);
You may assume that the keyword contains only lowercase alphabetic characters a - z.

The main should implement a testing interface similar to the one in Task B, 
the user enters the plaintext and the keyword, and the program reports the ciphertext.

Example:
$ ./vigenere

Enter plaintext: Hello, World!
Enter keyword  : cake
Ciphertext     : Jevpq, Wyvnd!
*/

#include <iostream>
#include <cctype>
using namespace std;

char shiftChar(char c, int kshift) {
    if(int(c) >= 65 && int(c) <= 90) { // 65 to 90, uppercase letters
        c += kshift; // whatever shift is based on keyword, increases c ascii code

        if(c > 90) { // last letter of alphabet, make it wrap around 
            c -= 26; // 26 letters in alphabet, wraps around. 
            return c;
        }

        return c;
    } else if(int(c) >= 97 && int(c) <= 122) { // 97 to 122, lowercase letters
        int a = int(c) + kshift; // shift c by keyword and store into a

        if(a > 122) {
            a -= 26; // wrap the alphabet around
            c = a; // store value of a into c

            return c;
        }

        c = a; 

        return c;
    }

    return c;
}

string encryptVigenere(string plaintext, string keyword) {
    char c, keyc;
    int n;

    for(int i = 0; i < plaintext.length(); i++) { // reads in all plaintext chars
        if(n > keyword.size() - 1) { // keyword - 1 to not include last letter
            n = 0;
        }

        c = plaintext[i]; // all letters executed by loop are stored into i every iteration
        keyc = keyword[n]; // read in the keyword 

        int kshift = (int(keyc) - 97); // 97 is when lowercase alphabet starts

        if(isalpha(c) == 0) {  // checks if c is an alphabetical char, 0 is false
            plaintext[i] = shiftChar(c, 0); // no shift, display default (for non alphabetical chars)
        } else {
            plaintext[i] = shiftChar(c, kshift); // shift if part of alphabet (lowercase)
            n++; // increase size to prevent overflow
        }
    }

    return plaintext;
}

int main() {
    string plaintext, kshift;

    cout << "Enter plaintext: ";
    getline(cin, plaintext);

    cout << "Enter keyword: ";
    cin >> kshift;

    cout << "Ciphertext: " << encryptVigenere(plaintext, kshift);

    return 0;
}