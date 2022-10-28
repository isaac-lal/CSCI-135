/*
Author: Nawang Sherpa
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Homework E6.8

Write a function: bool equals(int a[], int a_size, int b[], int b_size) that checks whether two arrays have the same elements in the same order.
*/

#include <iostream>
using namespace std;

bool equals(int a[], int a_size, int b[], int b_size) {
    if(a_size != b_size) { // if the sizes are not equal, return false
        return false;
    } else {
        for(int i = 0; i < a_size; i++) { // loop through the array
            if(a[i] != b[i]) { // if the elements are not equal, return false
                return false;
            }
        }
    }
    return true; // if the sizes are equal and the elements are equal, return true
}

