/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 1 - Task D

Write a program maze_runner_modded.cpp that can stream in a maze and set up the array 
then take in directions to see if they can traverse the custom maze.

The format for the maze will be as follows, and will always be a 10x10 size array:

Row 0 of maze
Row 1 of maze
...
Row 9 of maze

row column of starting location
row column of ending location
When reading input file maze_and_directions.txt:

1 1 1 1 1 1 1 1 1 1
0 0 1 0 0 0 1 0 0 1
1 0 1 0 1 0 1 1 0 1
1 0 0 0 1 0 0 0 0 1
1 1 1 0 1 1 1 0 1 1
1 1 0 0 0 1 0 0 0 1
1 1 1 1 0 0 0 1 0 1
1 0 0 0 0 1 0 1 1 1
1 0 1 1 0 1 0 0 0 1
1 0 1 1 1 1 1 1 1 1

1 0
9 1

;

R DDRR UU R R D D ;
R DDRRD D RDDLLLDD;
DRL RUDDRRDD LLLLL;
The program should report:

$ ./maze_runner_modded < maze_and_directions.txt
You are stuck in the maze.
You got out of the maze.
You are stuck in the maze.
An additional note on how to test maze programs
In addition to writing your formulas into files, remember that your program still accepts the input from the keyboard 
(Hey, do you see the benefit of input redirection? The program can work great on both keyboard and file inputs!)

When typing the input from the keyboard, the key combination Ctrl+D emulates the End-of-file situation, telling the program that the input has ended.

So, you can test your program like this:

$ ./maze_runner
R R U D R <Enter> <Ctrl+D>
You are stuck in the maze.
(finalizing your input by pressing Enter and Ctrl+D).
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    int maze[10][10];
    int startRow, startCol, endRow, endCol, row, col;

    // This loop creates the values of the CUSTOM maze
    for(int r = 0; r < 10; r++) {
        for(int c = 0; c < 10; c++) {
            cin >> maze[r][c];
        }
    }

    // cin the inputs of the start of row and col + end of row and col
    cin >> startRow >> startCol >> endRow >> endCol;
    row = startRow; // make the value of row startRow
    col = startCol; // same with col

    string directions;
    while(directions != ";") {
        cin >> directions;
    }

    string s;
    while(cin >> s) {
        string arr[s.size()];

        for(int i = 0; i < s.size(); i++) {
            arr[i] = s[i];
        }
        
        for(string i: arr) { //for each element in the array
            if(i == ";") {
                if(row == endRow && col == endCol) {
                    cout << "You got out of the maze." << endl;
                } else {
                    cout << "You are stuck in the maze." << endl;
                }

                row = startRow;
                col = startCol;
            }           

            if(i == "R" && maze[row][col + 1] != 1) {
                col++;
            } else if(i == "L" && maze[row][col - 1] != 1) {
                col--;
            } else if(i == "U" && maze[row - 1][col] != 1) {
                row--;
            } else if(i == "D" && maze[row + 1][col] != 1) {
                row++;
            } else {
                row = row;
                col = col;
            }
        }
    }
}