/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 3B

Write a program minmax.cpp that finds the minimum and maximum storage in East basin in 2018.

Example (using made up numbers):
$ ./minmax
minimum storage in East basin: 59.88 billion gallons
MAXimum storage in East basin: 81.07 billion gallons

Hint:
The program should read the file line by line, while keeping track of what is the highest 
and the lowest storage level in the basin so far. In the end, after reading the entire file, 
the found values will be the minimum and the maximum storage levels for the entire year.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

int main() {
    ifstream fin("Current_Reservoir_Levels.tsv");

    if(fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // exit if failed to open the file
    }

    string junk;        // new string variable
    getline(fin, junk); // read one line from the file

    string date;
    double eastSt, eastEl, westSt, westEl, min = 999999999999999999, max = 0;
    
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
        // this loop reads the file line-by-line
        // extracting 5 values on each iteration 
        
        fin.ignore(INT_MAX, '\n'); //skips to the end of line, 
                            //ignorring the remaining columns 

        // for example, to print the date and East basin storage:
        // cout << date << " " << eastSt << endl;
        
        if(eastSt < min) {
		    min = eastSt;
        } 
        
        if(eastSt > max) {
		    max = eastSt;
        }
    }  

    cout << "minimum storage in East basin: " << min << " billion gallons" << endl;
    cout << "MAXimum storage in East basin: " << max << " billion gallons" << endl;

    fin.close();
}