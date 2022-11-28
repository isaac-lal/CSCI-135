#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() //print a table of powers, x to the nth
{
    const int NMAX = 4;
    const double XMAX = 10;
    for (int n = 1; n <= NMAX; n++) { // Print table header
        cout << setw(10) << n; 
    }
    cout << endl;
    for (int n = 1; n <= NMAX + 1; n++) {
        cout << setw(10) << "xxxxxxxxxx"; 
    }
    cout << endl;
    for (double x = 1; x <= XMAX; x++) {// Print table row
        for (int n = 1; n <= NMAX; n++) //print each column
        cout << setw(10) << pow(x, n);
        cout << endl;
    }
}