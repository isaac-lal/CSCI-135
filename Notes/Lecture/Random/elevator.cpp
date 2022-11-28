// Lecture 9/12: Elevator 

#include <iostream>
using namespace std;

int main() {
    int floor, actual_floor;

    cout << "Floor: " << endl;
    cin >> floor;

    if (floor > 13) {
        actual_floor = floor - 1;
    } else {
        actual_floor = floor;
    }

    cout << "The elevator will travel to the actual floor " << actual_floor << endl;

    return 0;
}