/* 
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 7B

To count open blocks, we need to count how many curly braces get opened and closed on each line, so we need to count { and }

Write a function

int countChar(string line, char c);
that scans the line and returns the number of occurrences of the character c.

Write a new program indent.cpp that enhances the program from the previous task. As it reads the input line by line, 
it should also count the number of open and closed { } in it, and keep track of how many blocks is currently open at the beginning of each line.

In the listing below, the number of open blocks is shown on the left:

0   int main(){
1   // Hi, I'm a program!
1   int x = 1; 
1   for(int i = 0; i < 10; i++) {
2   cout << i;
2   cout << endl;
2   }
1   }
Then instead of printing the number of open blocks, add that number of tabs '\t' at the beginning of each line, and you will get:

int main(){
    // Hi, I'm a program!
    int x = 1; 
    for(int i = 0; i < 10; i++) {
        cout << i;
        cout << endl;
        } // <-- closing for loop
    }     // <-- closing main
Notice that the closing curly braces are indented one level further than what they should be.

To fix that, when indenting the line, check its very first character. If it is a closing curly brace }, its indentation level should be reduced by one:

int main(){
    // Hi, I'm a program!
    int x = 1; 
    for(int i = 0; i < 10; i++) {
        cout << i;
        cout << endl;
    } 
}     

*/

#include <iostream>
using namespace std;

string removeLeadingSpaces(string line) {
    int index = 0;

    while(isspace(line[index])) {
        index++;
    }
        
    return line.substr(index);
}

int countChar(string line, char c) {
    int count = 0;

    for(int i = 0; i < line.length(); i++) {
        if(line[i] == c) {
            count++;
        }
    }

    return count;
}

int main() {
    string line;
    char c;
    int count = 0;

    while(getline(cin, line, '\n')) {

        if(removeLeadingSpaces(line)[0] == '}') {
            for(int i = 0; i < count - 1; i++) {
                cout << "\t"; 
            }
        } else {
            for(int i = 0; i < count; i++) {
                cout << "\t";
            }
        }

        count -= countChar(line, '}');
        count += countChar(line, '{');
        cout << removeLeadingSpaces(line) << endl;
    }

    return 0;
}