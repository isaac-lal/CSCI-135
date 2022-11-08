/* 
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Homework E7.1 

Write a function
void sort2(double* p, double* q)
that receives two pointers and sorts the values to which they point. If you call
sort2(&x, &y)
then x <= y after the call.
*/

#include <iostream>
using namespace std;

void sort2(double* p, double* q) {
    if(*p > *q) {
        double swap = *q;
        *q = *p;
        *p = swap;
    } 
}

int main() {
    double x, y;

    cout << "Enter number for x: ";
    cin >> x;
    cout << "Enter number for y: ";
    cin >> y;
    
    sort2(&x, &y);

    cout << "x is now: " << x << endl;
    cout << "y is now: " << y << endl;

    return 0;
}