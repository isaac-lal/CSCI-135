/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 3D

Write a program reverse-order.cpp which asks the user to input two dates (earlier date then later date). 
The program should report the West basin elevation for all days in the interval in the reverse chronological 
order (from the later date to the earlier).

Example:
$ ./reverse-order
Enter earlier date: 05/29/2018
Enter later date: 06/02/2018

06/02/2018  590.22 ft
06/01/2018  590.23 ft
05/31/2018  590.24 ft
05/30/2018  590.26 ft
05/29/2018  590.32 ft

Hint: If for the previous tasks you did not use arrays, 
here you really have to read the data into arrays first, and 
only then report them in the required order.
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
    string date, earlierDate, laterDate, arrDate[365];
    double eastSt, eastEl, westSt, westEl, arrWestEl[365];

    cout << "Enter earlier date: " << endl;
    cin >> earlierDate;
    cout << "Enter later date: " << endl;
    cin >> laterDate;

    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
        // this loop reads the file line-by-line
        // extracting 5 values on each iteration 
        
        fin.ignore(INT_MAX, '\n'); //skips to the end of line, 
                            //ignorring the remaining columns 

        // for example, to print the date and East basin storage:
        // cout << date << " " << eastSt << endl;

        if(date >= earlierDate && date <= laterDate) {
            line++;
            arrDate[line] = date;
            arrWestEl[line] = westEl;
        } 
    }

    for(int i = line; i > 0; i--) {
        cout << arrDate[i] << "  " << arrWestEl[i] << " ft" << endl;
    }

    fin.close();
}
