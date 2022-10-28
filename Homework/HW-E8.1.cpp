/*
Author: Nawang Sherpa
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Homework E8.1

Write a program that carries out the following tasks:  Open a file with the name hello.txt.  Store the message “Hello, World!” in the file.  Close the file.  Open the same file again.  Read the message into a string variable and print it.  Close the file.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
   ofstream myfile;
    myfile.open("hello.txt");
    myfile << "Hello, World!";
    myfile.close();

    ifstream myfile2;
    myfile2.open("hello.txt");
    string line;
    getline(myfile2, line);
    cout << line << endl;
    return 0;

}

