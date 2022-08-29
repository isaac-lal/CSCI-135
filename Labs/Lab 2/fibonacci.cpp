/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 2D

Write a program fibonacci.cpp, which uses an array of ints to compute 
and print all Fibonacci numbers from F(0) to F(59).

Example:
0 
1 
1 
2 
3 
5 
8 
13 
...

Once your program is complete and works, check carefully the values printed on the screen. 
Specifically, what is happening when the numbers approach two billions? We expect that at some point the numbers 
start diverging from what they should be. Describe what you observe and explain why it is happening in a program comment.
*/

#include <iostream>
using namespace std;

int main() {
    // identify fibonacci array up to 60
    int fib[60];

    // give first two values before the loop
    fib[0] = 0;
    fib[1] = 1;

    // start loop at 2 since 0 and 1 are defined, up to 60
    for(int i = 2; i < 60; i++) {
        // fib[2] = fib[1] + fib[0] = 1
        // fib[3] = fib[2] + fib[1] = 3
        // fib[4] = fib[3] + fib[2] = 5
        // fib[5] = fib[4] + fib[3] = 8
        // fib[6] = fib[5] + fib[4] = 13

        // calculates fibonacci up to 59 and output 
        fib[i] = fib[i-1] + fib[i-2];
        cout << fib[i] << endl;
    }

    return 0;
}