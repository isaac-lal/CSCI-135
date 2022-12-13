/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 12B

Make a program called optimism.cpp that implements the 
function vector<int> goodVibes(const vector<int>& v); that, given a vector of integers, 
returns a vector with only the positive integers in the same order.

vector<int> v{1,2,-1,3,4,-1,6};

goodVibes(v); // returns [1,2,3,4,6]
*/

#include <iostream>
#include <vector>

std::vector<int> goodVibes(const std::vector<int> v);

int main() {
    std::vector<int> v{-1, -1, -1, -1, 4, -1, -1};
    std::vector<int> ve = goodVibes(v);
    
    std::cout << "The vector size is " << ve.size() << "\n";

    for(int i = 0; i < ve.size(); i++) {
        std::cout << ve[i] << " ";
    }

    return 0;
}

std::vector<int> goodVibes(std::vector<int> v) {
    for(int i = 0; i < v.size(); i++) {
        if(v[i] < 0) {
            v.erase(v.begin() + i);
            i--;
        }
    }

    return v;
}
