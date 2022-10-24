/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 6B

Write a program caesar.cpp with functions implementing Caesar cipher encryption:

// A helper function to shift one character by rshift
char shiftChar(char c, int rshift);

// Caesar cipher encryption
string encryptCaesar(string plaintext, int rshift);
The argument rshift is the magnitude of the right shift. 
For the sake of the lab, you may assume it to be in the range 0 ≤ rshift ≤ 25 
(although, implementing it correctly for an arbitrary integer shift is also possible, of course).

Your functions should preserve case, and any non-alphabetic characters should be left unchanged. For example,

encryptCaesar("Way to Go!", 5) == "Bfd yt Lt!"
Feel free to write more additional helper functions when you need them.

The main function should ask the user to input a plaintext sentence, 
then enter the right shift, and report the ciphertext computed using your encryption function.

Example:
$ ./caesar

Enter plaintext: Hello, World!
Enter shift    : 10
Ciphertext     : Rovvy, Gybvn!
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
        }

        return c;
    } else if(int(c) >= 97 && int(c) <= 122) { // 97 to 122, lowercase letters
        int a = int(c) + rshift; // shift c and store into a

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

string encryptCaesar(string plaintext, int rshift) {
    char c;

    for(int i = 0; i < plaintext.length(); i++) {
        c = plaintext[i];
        plaintext[i] = shiftChar(c, rshift); // call the function to shift user inputted text
    }

    return plaintext;
}

int main() {
    string plaintext;
    int rshift;

    cout << "Enter plaintext: ";
    getline(cin, plaintext);

    cout << "Enter shift: ";
    cin >> rshift;

    cout << "Ciphertext: " << encryptCaesar(plaintext, rshift);

    return 0;
}