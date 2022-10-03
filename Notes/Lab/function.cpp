#include <iostream>

using namespace std;

/* Defining a function that computes the sum of three integers */
int sum(int a, int b, int c) { 
    return a + b + c;          
}

int main() {
    // We call it with the actual arguments 1, 20, 300,
    // and save the result in a variable x
    int x = sum(1, 20, 300);  
    cout << x << endl;                     // Prints 321
}