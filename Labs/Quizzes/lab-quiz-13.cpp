/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab Quiz 13

Vectors

Define function vector<int> makeVector(int n) which, 
if n is positive, return a vector of ints of 0 to n-1, 
otherwise, return an empty vector.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> makeVector(int n);

int main() {
    int a;
    cout << "Enter a number: ";
    cin >> a;

    vector<int> av = makeVector(a);
    cout << "The vector size is " << av.size() << endl;

    for(int i = 0; i < av.size(); i++) {
        cout << av[i] << " ";
    }
}

vector<int> makeVector(int n) {
    vector<int> temp;

    if(n > 0) {   
        for(int i = 0; i < n; i++) {
            temp.push_back(i);
        }

        return temp;
    }
    return temp;
}