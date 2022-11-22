/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Homework E7.16

Define a structure Point. A point has an x- and a y-coordinate. Write a function double
distance(Point a, Point b) that computes the distance from a to b. Write a program
that reads the coordinates of the points, calls your function, and displays the result.
*/

#include <iostream>
#include <cmath>
using namespace std;

class Point {
public:
    double x;
    double y;
};

double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
    Point p1, p2;

    cout << "Enter Point 1 x and y: " << endl;
    cin >> p1.x >> p1.y;
    cout << "Enter Point 2 x and y: " << endl;
    cin >> p2.x >> p2.y;

    cout << distance(p1, p2) << endl;
    
    return 0;
}