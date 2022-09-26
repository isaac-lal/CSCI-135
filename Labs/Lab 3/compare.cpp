/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 3C

Write a program compare.cpp that asks the user to input two dates 
(the beginning and the end of the interval). The program should check each day 
in the interval and report which basin had higher elevation on that day by printing 
“East” or “West”, or print “Equal” if both basins are at the same level.

Example:
$ ./compare
Enter starting date: 09/13/2018
Enter ending date: 09/17/2018

09/13/2018 West
09/14/2018 West
09/15/2018 West
09/16/2018 West
09/17/2018 West

Explanation:
Date	East (ft)	West (ft)	 
09/13/2018	581.94	582.66	West is higher
09/14/2018	581.8	582.32	West is higher
09/15/2018	581.62	581.94	West is higher
09/16/2018	581.42	581.55	West is higher
09/17/2018	581.16	581.2	West is higher
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

    int line = 0;
    string date, startDate, endDate;
    double eastSt, eastEl, westSt, westEl;

    cout << "Enter starting date: " << endl;
    cin >> startDate;
    cout << "Enter ending date: " << endl;
    cin >> endDate;

    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
        // this loop reads the file line-by-line
        // extracting 5 values on each iteration 
        
        fin.ignore(INT_MAX, '\n'); //skips to the end of line, 
                            //ignorring the remaining columns 

        // for example, to print the date and East basin storage:
        // cout << date << " " << eastSt << endl;

        if(date == startDate) {
            line++;
        } else if(date > endDate) {
            break;
        }

        for(int i = 0; i < line; i++) {
            if(eastEl > westEl) {
                cout << date << " East" << endl;
            } else if(eastEl < westEl) {
                cout << date << " West" << endl;
            } else {
                cout << date << " Equal" << endl;
            }
        } 
    }

    fin.close();
}