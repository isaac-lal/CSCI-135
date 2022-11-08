/* 
Author: 
Course: CSCI-135
Instructor: Genady Maryas
Assignment: HW-E7.1

Write a function void sort2(double* p, double* q) that receives two pointers and sorts the values to which they point. If you call sort2(&x, &y) then x <= y after the call.

*/

#include <iostream>
using namespace std;

void sort2(double* p, double* q) {
    double temp = 0;

    if(*p > *q) {
        temp = *p;
        *p = *q;
        *q = temp;
    }
}


