#include <iostream>
using namespace std;

int main()
{
    const double RATE = 5;
    const double INITIAL_BALANCE = 10000;
    const double TARGET = 2 * INITIAL_BALANCE;
    double balance = INITIAL_BALANCE;
    int year = 0;

    while (balance < TARGET) {
        year++;
        double interest = balance * RATE / 100;
        balance = balance + interest;
    }
    
    cout << "The investment doubled after " << year << " years." << endl;
    
    return 0;
}