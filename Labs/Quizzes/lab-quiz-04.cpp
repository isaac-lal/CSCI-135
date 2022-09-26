/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab Quiz 04

Reading Files 

Open and read a file called "data.txt", which contains lines of text with names of colors 
and their RGB values, like this: red FF0000 etc... Read and print each line. 
Close the file after processing it.
*/

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("data.txt");

    string color, rgb;
    
    while(fin >> color >> rgb) {
        cout << color << " " << rgb << endl;
    }
    
    fin.close();
}