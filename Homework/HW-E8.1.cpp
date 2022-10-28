/* 
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Homework E8.1

Write a program that carries out the following tasks:
Open a file with the name hello.txt.
Store the message “Hello, World!” in the file.
Close the file.
Open the same file again.
Read the message into a string variable and print it.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream fileRead("hello.txt"); // opens file
    fileRead << "Hello, World!"; // stores message
    fileRead.close(); // closes file
    ifstream filePrint("hello.txt"); //opens file again

    string hello; 
    getline(filePrint, hello);
    cout << hello; // prints text in file as string

    filePrint.close();

    return 0; 
}