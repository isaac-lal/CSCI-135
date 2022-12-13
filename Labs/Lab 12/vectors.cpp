/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 12A

A big benefit of vectors is their ability to be returned from functions. 
For this task, program a function called vector<int> makeVector(int n) that returns 
a vector of n integers that range from 0 to n-1. Call your program vectors.cpp. 

Your function must be implemented outside the main function and must return a vector.
*/

#include <iostream>
#include <vector>

std::vector<int> makeVector(int n);

int main() {
    int a;
    
    std::cout << "Enter a number: ";
    std::cin >> a;

    std::vector<int> av = makeVector(a);

    std::cout << "\n" << "The vector size is " << av.size() << "\n";

    for(int i = 0; i < av.size(); i++) {
        std::cout << av[i] << " ";
    }
}

std::vector<int> makeVector(int n) {
    std::vector<int> temp;

    if(n > 0) {
        for(int i = 0; i < n; i++) {
            temp.push_back(i);
        }

        return temp;
    }

    return temp;
}