/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 12C

Make a program called fusion.cpp that implements the 
function void gogeta(vector<int> &goku, vector<int> &vegeta) that appends elements of the second vector 
into the first and empties the second vector. For example:

vector<int> v1{1,2,3};
vector<int> v2{4,5};

gogeta(v1, v2); // v1 is now [1,2,3,4,5] and v2 is empty.
*/

#include <iostream>
#include <vector>

void gogeta(std::vector<int> &goku, std::vector<int> &vegeta); 

int main() {
    std::vector<int> v1{1,2,3};
    std::vector<int> v2{4,5};

    for(int i = 0; i < v1.size(); i++) {
        std::cout << "element " << i<< "v1:"<< v1[i] << " v2: " << v2[i] << ".\n";
    }

    gogeta(v1,v2);

    for(int i = 0; i < v1.size(); i++) {
        std::cout << "element "<< i << " v1 " << v1[i] << "\n";
    }

    for(int i = 0; i < v2.size(); i++) {
        std::cout << " v2: " << v2[i] << ".\n";
    }

    return 0;
}

void gogeta(std::vector<int> &goku, std::vector<int> &vegeta) {
    for(int i = 0; i <vegeta.size(); i++) {
        goku.push_back(vegeta[i]);
    }
    
    vegeta.clear();
}