/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 6D

Implement two decryption functions corresponding to the above ciphers. When decrypting ciphertext, ensure that the produced decrypted string is equal to the original plaintext:

decryptCaesar(ciphertext, rshift) == plaintext
decryptVigenere(ciphertext, keyword) == plaintext
Write a program decryption.cpp that uses the above functions to demonstrate encryption and decryption for both ciphers.

It should first ask the user to input plaintext, then ask for a right shift for the Caesar cipher and report the ciphertext and its subsequent decryption. After that, it should do the same for the Vigenere cipher.

Example:
$ ./decryption

Enter plaintext: Hello, World!

= Caesar =
Enter shift    : 10
Ciphertext     : Rovvy, Gybvn!
Decrypted      : Hello, World!

= Vigenere =
Enter keyword  : cake
Ciphertext     : Jevpq, Wyvnd!
Decrypted      : Hello, World!
(When reporting decrypted strings, they should be the result of applying decryption functions to the ciphertext, not the original plaintext variable.)
*/

#include <iostream>
#include <cctype>
using namespace std;

char shiftChar(char c, int rshift) {
    if(int(c) >= 65 && int(c) <= 90) { // 65 to 90, uppercase letters
        c += rshift; // whatever shift is, increases c ascii code

        if(c > 90) { // last letter of alphabet, make it wrap around 
            c -= 26; // 26 letters in alphabet, wraps around. 
            return c;
        } else if(c < 65) {
            c += 26; // for decryption, when letters fall outside range 
            return c;
        }

        return c;
    } else if(int(c) >= 97 && int(c) <= 122) { // 97 to 122, lowercase letters
        int a = int(c) + rshift; // shift c and store into a

        if(a > 122) {
            a -= 26; // wrap the alphabet around
            c = a; // store value of a into c
            return c;
        } else if(a < 97) {
            a += 26; 
            c = a;
            return c;
        }

        c = a; 
        return c;
    }

    return c;
}

string encryptCaesar(string plaintext, int rshift) {
    char c;

    for(int i = 0; i < plaintext.length(); i++) {
        c = plaintext[i];
        plaintext[i] = shiftChar(c, rshift); // call the function to shift user inputted text
    }

    return plaintext;
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

string decryptCaesar(string ciphertext, int rshift) {
    char c;

    for(int i = 0; i < ciphertext.length(); i++) {
        c = ciphertext[i]; 
        ciphertext[i] = shiftChar(c, rshift * (-1)); // shift every number for its negative value for decryption 
    }

    return ciphertext;
}

string decryptVigenere(string ciphertext, string keyword) {
    char c, keyc;
    int n;

    for(int i = 0; i < ciphertext.length(); i++) { // reads in all plaintext chars
        if(n > keyword.size() - 1) { // keyword - 1 to not include last letter
            n = 0;
        }

        c = ciphertext[i]; // all letters executed by loop are stored into i every iteration
        keyc = keyword[n]; // read in the keyword 

        int kshift = (int(keyc) - 97); // 97 is when lowercase alphabet starts
        kshift *= -1;

        if(isalpha(c) == 0) {  // checks if c is an alphabetical char, 0 is false
            ciphertext[i] = shiftChar(c, 0); // no shift, display default (for non alphabetical chars)
        } else {
            ciphertext[i] = shiftChar(c, kshift); // shift if part of alphabet (lowercase)
            n++; // increase size to prevent overflow
        }
    }

    return ciphertext;
}

int main() {
    string plaintext, keyword;
    int rshift;

    cout << "Enter plaintext: ";
    getline(cin, plaintext);

    cout << "\n= Caesar =\n";

    cout << "Enter shift: ";
    cin >> rshift;

    cout << "Ciphertext: " << encryptCaesar(plaintext, rshift) << endl;
    cout << "Decrypted: " << decryptCaesar(encryptCaesar(plaintext, rshift), rshift) << endl;

    cout << "\n= Vigenere =\n";

    cout << "Enter keyword: ";
    cin >> keyword;

    cout << "Ciphertext: " << encryptVigenere(plaintext, keyword) << endl;
    cout << "Decrypted: " << decryptVigenere(encryptVigenere(plaintext, keyword), keyword);

    return 0;
}