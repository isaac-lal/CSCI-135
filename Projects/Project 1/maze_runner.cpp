/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 1 - Task B

Create a file called maze_runner.cpp that will implement the two sub-tasks below:

Sub-Task A) Initializing the map
Add the following code as the maze that will be traversed (This is a 2-dimensional array).

int maze[6][6] = {
   1,0,1,1,1,1,
   1,0,0,0,1,1,
   1,0,1,0,0,1,
   1,0,1,0,1,1,
   1,0,0,0,0,0,
   1,1,1,1,1,1
};
Please note that the start to the maze is at row 0, column 1 and the exit is at row 4, column 5.

Sub-Task B) Don’t get lost!
With the maze being provided, we want to stream in a list of directions as to determine whether or not it correctly traverses the maze.

Imagine you have a directions.txt with the list of directions as follows:

D R R D R
If you redirect the file into your program, it should compute and print the answer:

$ ./maze_runner < directions.txt
You are stuck in the maze.
It may sound tricky, but it is actually easy to write such a program, and you already know all the needed tools. 
Just think carefully how to put it all together.

Specifically, write a program maze_runner.cpp that reads from the cin a sequence of 
one or more letters and treat it as a list of directions that take you through the maze array 
to see whether or not you exit the maze at the correct location or not. Space characters can be anywhere in the input. 
After the input ends (end-of-file is reached), the program should compute and print the result of the input summation.

Possible input for your program may look like this:
D D L

D DD DR RRR

D R R DR DDLDD RR

(Each of the inputs above is a separate file containing one single list of instructions, even if it spans multiple lines.)

The corresponding outputs should be:
You are stuck in the maze.
You got out of the maze.
You got out of the maze.
*/

#include <iostream>
using namespace std;

int main() {
    string s;
    int maze[6][6] = { // starts at [0][0]
        1,0,1,1,1,1, // row 0, column 1 = start
        1,0,0,0,1,1,
        1,0,1,0,0,1,
        1,0,1,0,1,1,
        1,0,0,0,0,0,
        1,1,1,1,1,1
    }; 
    int row = 0, col = 1;

    while(cin >> s) { // While the reading operation is a success
        if(s == "R" && maze[row][col + 1] == 0) {
            col++;
        } else if(s == "L" && maze[row][col - 1] == 0) {
            col--;
        } else if(s == "U" && maze[row - 1][col] == 0) {
            row--;
        } else if(s == "D" && maze[row + 1][col] == 0) {
            row++;
        } 
    }

    if(row == 4 && col == 5) { // WIN CONDITION: maze[4][5]
        cout << "You got out of the maze." << endl;
    } else {
        cout << "You are stuck in the maze. " << endl;
    }
}
