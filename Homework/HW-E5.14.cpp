/* 
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Homework E5.14

Write a function void sort2(int& a, int& b) that swaps the values of a and b if a is
greater than b and otherwise leaves a and b unchanged. For example,
int u = 2;
int v = 3;
int w = 4;
int x = 1;
sort2(u, v); // u is still 2, v is still 3
sort2(w, x); // w is now 1, x is now 4
*/

#include <iostream>
using namespace std;

void sort2(int& a, int& b) {
    if(a > b) {
        int swap = b;
        b = a;
        a = swap;
    } 
}

int main() {
    int a, b;

    cout << "Enter number for a: ";
    cin >> a;
    cout << "Enter number for b: ";
    cin >> b;
    
    sort2(a, b);

    cout << "a is now: " << a << endl;
    cout << "b is now: " << b << endl;

    return 0;
}