#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int* counts[4];
    // Allocate the rows
    for (int i = 0; i < 4; i++) {
        counts[i] = new int[i + 1];
        for (int j = 0; j <= i; j++) {
            counts[i][j] = 0;
        }
    }
    const int RUNS = 7;
    // Simulate 7 balls
    for (int run = 0; run < RUNS; run++) {
        // Add a ball to the top
        counts[0][0]++;
        // Have the ball run to the bottom
        int j = 0;
        for (int i = 1; i < 4; i++) {
            //If even, move down, else down and right:
            if (rand() % 2) {
                j++;
            }
            counts[i][j]++;
        }
    }
    // Print all counts
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j <= i; j++) {
            cout << setw(4) << counts[i][j];
        }
        cout << endl;
    }
    // Deallocate the rows
    for (int i = 0; i < 4; i++) {
        delete[] counts[i];
    }
    return 0;
}