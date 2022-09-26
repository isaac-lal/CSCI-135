/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 1 - Task A

Create a file called direction_reader.cpp that reads a sequence of letters from cin and prints out its corresponding direction.

‘R’: go Right of the current location
‘L’: go Left of the current location
‘U’: go Up from the current location
‘D’: go Down from the current location
Example

If you have a file movement.txt that contains:

R R D L L U R
Then if you redirect it into the program, it should report:

$ ./maze_setup < movement.txt
Right
Right
Down
Left
Left
Up
Right
*/

#include <iostream>
using namespace std;
int main() {
    string s;

    while(cin >> s) { // While the reading operation is a success
        if(s == "R") {
            cout << "Right" << endl;  // print the read word
        } else if(s == "L") {
            cout << "Left" << endl;  // print the read word
        } else if(s == "U") {
            cout << "Up" << endl;  // print the read word
        } else if(s == "D") {
            cout << "Down" << endl;  // print the read word
        } 
    }
}