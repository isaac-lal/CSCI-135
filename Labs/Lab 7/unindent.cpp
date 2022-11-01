/* 
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 7A

Before we make a program that indents source code files, let’s make a program that unindents them.

Start by writing a function

string removeLeadingSpaces(string line);
that takes one line of code as input and returns its copy without leading spaces and tabs:

removeLeadingSpaces("       int x = 1;  ") == "int x = 1;  "
Make use of the function isspace defined in <cctype> to check if a character is a whitespace. Your function should probably iterate over the input string, skip all spaces, and after it finds the first non-space character, start accumulating the characters into a new string, which will be returned.

Write a program unindent.cpp that reads input from cin and prints out each input line with leading spaces removed.

Example:
To test, create a badly indented file, for instance, called bad-code.cpp:

                int main(){
           // Hi, I'm a program!
int x = 1; 
    for(int i = 0; i < 10; i++) {
cout << i;
          cout << endl;
 }
    }
Since our unindent program reads its input from cin, the badly indented text can be fed into it using standard input redirection:

$ ./unindent < bad-code.cpp
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

int main() {
    string line;

    while(getline(cin, line)) {
        cout << removeLeadingSpaces(line) << endl;
    }

    return 0;
}