/* 
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 5A, 5B, 5C, 5D, 5E, 5F, 5G

TASK A:
Write a program numbers.cpp that defines a function

bool isDivisibleBy(int n, int d);
If n is divisible by d, the function should return true, otherwise return false.

For example:
isDivisibleBy(100, 25) == true
isDivisibleBy(35, 17) == false
The program should also have a main function that tests your code. For example, it can ask the user 
to input two integer numbers and print Yes if the first number is divisible by the second, otherwise print No.

--------------------------------------------------------------------------------------------------------------
TASK B:
A prime number is an integer greater or equal to 2 that is only divisible by 1 and by itself. The first few primes are:
2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 …

N is a prime if and only if it is not divisible evenly by any of the numbers from 2 to N−1. Let’s implement this 
decision as a function.

In the same program numbers.cpp, add a function

bool isPrime(int n);
The function should return true if n is a prime, otherwise return false. Change the main function to test your new code.

--------------------------------------------------------------------------------------------------------------
TASK C: 
Add a function

int nextPrime(int n);
that returns the smallest prime greater than n.

For example:
nextPrime(14) == 17
nextPrime(17) == 19
Change the main function to test the new code.

--------------------------------------------------------------------------------------------------------------
TASK D:
Add a function

int countPrimes(int a, int b);
that returns the number of prime numbers in the interval a ≤ x ≤ b. Change the main function to test the new code.

A prime number N is called a twin prime if either N-2 or N+2 (or both of them) is also a prime.
For example, a prime 17 is a twin prime, because 17+2 = 19 is a prime as well.
The first few twin primes are: 3, 5, 7, 11, 13, 17, 19, 29, 31 …

--------------------------------------------------------------------------------------------------------------
TASK E:
Add a function

bool isTwinPrime(int n);
that determines whether or not its argument is a twin prime. Change the main function to test the new code.

--------------------------------------------------------------------------------------------------------------
TASK F:
Add a function

int nextTwinPrime(int n);
that returns the smallest twin prime greater than n. Change the main function to test the new code.

--------------------------------------------------------------------------------------------------------------
TASK G:
Add a function

int largestTwinPrime(int a, int b);
that returns the largest twin prime in the range a ≤ N ≤ b.
If there is no twin primes in range, then return -1.

For example:
largestTwinPrime(5, 18) == 17
largestTwinPrime(1, 31) == 31
largestTwinPrime(14, 16) == -1
Change the main function to test the new code.
*/

#include <iostream>
using namespace std;

// TASK A
bool isDivisibleBy(int n, int d) {
    // checks if n is divisible by d 
    if(d == 0) {
        return false;
    }

    if(n % d == 0) {
        return true;
    } else {
        return false;
    }
}

// TASK B
bool isPrime(int n) {
    if(n < 2) {
        return false;
    }

    for(int i = 2; i < n; i++) {
        if(isDivisibleBy(n, i)) {
            return false;
        }
    }

    return true;
}

// TASK C
int nextPrime(int n) {
    int i = n + 1;

    while( !(isPrime(i)) ) {
        i++;
    }

    return i;
}

// TASK D
int countPrimes(int a, int b) {
    int numPrimes = 0;

    for(int i = a; i <= b; i++) {
        if(isPrime(i)) {
            numPrimes++;
        }
    }

    return numPrimes;
}

// TASK E
bool isTwinPrime(int n) {
    if( !(isPrime(n)) ) {
        return false;
    }

    if(isPrime(n - 2) || isPrime(n + 2)) {
        return true;
    } else {
        return false;
    }
}

// TASK F
int nextTwinPrime(int n) {
    int i = n + 1; // same logic as nextPrime

    while( !(isTwinPrime(i)) ) {
        i++;
    }

    return i;
}

// TASK G
int largestTwinPrime(int a, int b) {
    for(int i = b; i >= a; i--) { // reversed for loop
        if(isTwinPrime(i)) {
            return i;
        } // defined function: isTwinPrime makes this task easy
    }

    return -1;
}

int main() {
    /* TASK A
    int divide, divideBy;

    cout << "Enter the number you want to divide: ";
    cin >> divide;
    cout << "Enter the number you want to divide by: ";
    cin >> divideBy;
    
    if(isDivisibleBy(divide, divideBy) == 1) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    */

    /* TASK B
    int prime;
    
    cout << "Enter a number: ";
    cin >> prime;

    if(isPrime(prime) == 1) {
        cout << "Prime" << endl;
    } else {
        cout << "Not Prime" << endl;
    }
    */ 

    /* TASK C
    int next;

    cout << "Enter a number: ";
    cin >> next;

    cout << nextPrime(next) << endl;
    */

    /* TASK D
    int count1, count2;

    cout << "Enter first number: ";
    cin >> count1;
    cout << "Enter second number: ";
    cin >> count2;

    cout << countPrimes(count1, count2) << endl;
    */

    /* TASK E
    int num;

    cout << "Enter a prime number: ";
    cin >> num;

    if(isTwinPrime(num) == 1) {
        cout << "This number is a twin prime";
    } else {
        cout << "This number is NOT a twin prime";
    }
    */

    /* TASK F
    int nextTwin;

    cout << "Enter a number: ";
    cin >> nextTwin;

    cout << nextTwinPrime(nextTwin) << endl;
    */

    // TASK G
    int twin1, twin2;

    cout << "Enter first number: ";
    cin >> twin1;
    cout << "Enter second number: ";
    cin >> twin2;

    cout << largestTwinPrime(twin1, twin2) << endl;
}