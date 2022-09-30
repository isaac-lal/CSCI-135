/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 1 - Task C

Write a better version of the program called maze_runner_plus.cpp that can evaluate multiple direction lists. Let’s use the semicolon symbol that must be used at the end of each direction in the input.

Assuming that the input file multiple_directions.txt looks as follows:

D D L R D D L R R U R R ;
D  RRRR ABLQPO D D L L R D V LL RRRR ;
D D D L CST
D D RRRR DD ;
When we run the program with that input, the output should evaluate all of the directions and print them each on its own line:

$ ./maze_runner_plus < multiple_directions.txt
You are stuck in the maze.
You got out of the maze.
You got out of the maze.
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    int maze[6][6] = {
        1,0,1,1,1,1,
        1,0,0,0,1,1,
        1,0,1,0,0,1,
        1,0,1,0,1,1,
        1,0,0,0,0,0,
        1,1,1,1,1,1
    };

    int row = 0, col = 1, len;
    string directions;

    while(cin >> directions) { // While the reading operation is a success
        len = directions.length();

        for(int i = 0; i < len; i++) {
            char s = directions[i];

            if(s == ';') {
                if(row == 4 && col == 5) {
                    cout << "You got out of the maze." << endl;
                } else {
                    cout << "You are stuck in the maze." << endl;
                }
            } else if(s == 'R' && (maze[row][col + 1] == 0 && col < 5)) {
                col++;
            } else if(s == 'L' && (maze[row][col - 1] == 0 && col > 0)) {
                col--;
            } else if(s == 'U' && (maze[row - 1][col] == 0 && row > 0)) {
                row--;
            } else if(s == 'D' && (maze[row + 1][col] == 0 && row < 5)) {
                row++;
            }
        }
    }
} 