/* 
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Homework E6.8

Write a function
bool equals(int a[], int a_size, int b[], int b_size)
that checks whether two arrays have the same elements in the same order.
*/

#include <iostream>
using namespace std;

bool equals(int a[], int a_size, int b[], int b_size) {
    if(a_size == b_size) {
        for(int i = 0; i < a_size; i++) {
            if(a[i] != b[i]) {
                return false;
            }
        }

        return true;
    } else {
        return false;
    }
}

int main() {
    int a[] = { }, b[] = { };

    if(equals(a, sizeof(a), b, sizeof(b)) == 1) {
        cout << "Similar";
    } else {
        cout << "Different";
    }
    
    return 0;
}