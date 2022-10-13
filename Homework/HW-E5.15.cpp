/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Homework E5.15

Write a function sort3(int& a, int& b, int& c) that swaps its three arguments to
arrange them in sorted order. For example,
int v = 3;
int w = 4;
int x = 1;
sort3(v, w, x); // v is now 1, w is now 3, x is now 4
Hint: Use multiple calls to the sort2 function of Exercise E5.14.
*/

#include <iostream>
using namespace std;

void sort2(int& num1, int& num2) {
    if(num1 > num2) {
        int swap = num2;
        num2 = num1;
        num1 = swap;
    } 
}

void sort3(int& a, int& b, int& c) {
    sort2(a, b);
    sort2(a, c);
    sort2(b, c);   
}

int main() {
    int a, b, c;

    cout << "Enter number for a: ";
    cin >> a;
    cout << "Enter number for b: ";
    cin >> b;
    cout << "Enter number for c: ";
    cin >> c;
    
    sort3(a, b, c);

    cout << "a is now: " << a << endl;
    cout << "b is now: " << b << endl;
    cout << "c is now: " << c << endl;

    return 0;
}