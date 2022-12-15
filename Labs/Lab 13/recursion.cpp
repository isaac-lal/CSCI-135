/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 13 - Tasks A, B, C, D, E, F

TASK A:
Write a program recursion.cpp, defining a function

void printRange(int left, int right);
that prints all numbers in range left ≤   x   ≤ right, separated by spaces. (Don’t use loops, global or static variables.)

A usage example:

int main() {
    printRange(-2, 10);
}
Will print:

-2 -1 0 1 2 3 4 5 6 7 8 9 10
When left > right, the range is empty and the program should not print any numbers.


TASK B:
In the same program recursion.cpp, add a function

int sumRange(int left, int right);
that computes the sum of all numbers in range left ≤   x   ≤ right. (Don’t use loops, global or static variables.)

A usage example:

int main() {
    int x = sumRange(1, 3);
    cout << This is << x << endl;   // 6
    
    int y = sumRange(-2, 10);
    cout << That is << y << endl;   // 52
}
What makes it different from the previous example, this function has to return the answer:

if the range is empty, the sum is zero.
Otherwise sum(left, right) = left + sum(left + 1, right).


TASK C:
In the same program, add a new function

int sumArray(int *arr, int size);
which receives an array (as a pointer to its first element) and the size of the array, and should return the sum of its elements. The function itself should not do any new dynamic memory allocations.

There are several approaches to this task:

One possible strategy is to define a helper function
sumArrayInRange(int *arr, int left, int right);
which adds up all elements of the passed array, but only for indexes in the interval left ≤ i ≤ right. It can be implemented very similarly to the function sumRange, but it should be adding the elements of the array instead of range indices.
Then sumArray(arr, size) can be defined as
sumArrayInRange(arr, 0, size-1).

Alternatively, can you maybe get away with just using the original function?
A usage example:

int main() {

    int size = 10;
    int *arr = new int[size]; // allocate array dynamically
    arr[0] = 12;
    arr[1] = 17;
    arr[2] = -5;
    arr[3] = 3;
    arr[4] = 7;
    arr[5] = -15;
    arr[6] = 27;
    arr[7] = 5;
    arr[8] = 13;
    arr[9] = -21;

    int sum1 = sumArray(arr, size); // Add all elements
    cout << "Sum is " << sum1 << endl;  // Sum is 43
    
    int sum2 = sumArray(arr, 5); // Add up first five elements
    cout << "Sum is " << sum2 << endl;  // Sum is 34

    delete[] arr;         // deallocate it
}


TASK D:
In the same program, add a new function

bool isAlphanumeric(string s);
which returns true if all characters in the string are letters and digits, otherwise returns false.

A usage example:

cout << isAlphanumeric("ABCD") << endl;        // true (1)
cout << isAlphanumeric("Abcd1234xyz") << endl; // true (1)
cout << isAlphanumeric("KLMN 8-7-6") << endl;  // false (0)
The logic is similar to the sumRange function:

if the sting is empty, return true.
Otherwise,
check the first character, and
check that the rest of the string is alphanumeric.
You may use the string function substr(pos, len), which extracts a substring. It takes two parameters, the starting position and the length of the substring. For example:

string msg = "ABCDEFGH";
cout << msg.substr(2, 4);   // CDEF (start at char [2] and
                            //       take 4 characters)

TASK E:
Add a new function

bool nestedParens(string s);
which returns true if the string is a sequence of nested parentheses:

Strings "", "()", "(())", "((()))" … are all correct sequences and should return true. Any other symbols or mismatching parenthesis should make the function return false.

A usage example:

  cout << nestedParens("((()))") << endl;      // true (1)
  cout << nestedParens("()") << endl;          // true (1)
  cout << nestedParens("") << endl;            // true (1)

  cout << nestedParens("(((") << endl;         // false (0)
  cout << nestedParens("(()") << endl;         // false (0)
  cout << nestedParens(")(") << endl;          // false (0)
  cout << nestedParens("a(b)c") << endl;       // false (0)


TASK F:
Alice and Bob inherited a collection of paintings. However, they will receive it only if the collection can be divided into two parts of exactly equal price. (Otherwise, it will be donated to a local art museum.)

Is the collection divisible into two exactly equal halves? We have to find the answer.

The prices of the paintings are provided as an array of integers. For example:

int prices [] = {10, 15, 12, 18, 19, 17, 13, 35, 33};
Here, the total sum is 172, so each person should receive the sum of 86. In this specific example, a solution exists, it is the following partition: (10 + 15 + 12 + 19 + 17 + 13) = (18 + 35 + 33) = 86.

How to solve the problem recursively?
Consider the example above. Is it possible to divide [10, 15, 12, 18, 19, 17, 13, 35, 33] into sums of 86 and 86?

Each item should go either to Alice or to Bob. Let’s take the first item, 10. Should we give it to Bob or Alice? In either case, there can be a solution. So, let’s try both options:



If we can give 10 to Alice, and the rest can be divided so that she gets 76 and Bob gets 86, then a solution exists (and Alice gets 10).

Also, if we can give 10 to Bob and the rest can be divided so that he gets 76 and Alice gets 86, then the solution also exists (and Bob gets 10).

Otherwise, there is no solution.

Programming task
In the same program, write a function:

bool divisible(int *prices, int size);
which returns true if the collection is divisible, and false otherwise. The prices are provided in the array prices, and size is the number of items in the array.

Your function should not allocate new memory dynamically. Pass the same array data into recursive function calls. If you need more variables such as left and right boundary variables, or the amounts that should be given to Alice and Bob, make a helper function with any necessary extra variables.

(It is possible to make the program to actually print out the solution, who gets which item. For that, in each of the YES branches, once you know that a solution to the subproblem exists, print the current item and the name of the person who gets it.)

This is not a simple task, but if you can do it, this is great!
*/

#include <iostream>
#include <string>
using namespace std;

void printRange(int left, int right);
int sumRange(int left, int right);
int sumArray(int *arr, int size);
bool isAlphanumeric(string s);
bool nestedParens(string s);
bool divisible(int *prices, int size);

int main() {
    /*
    // TASK A:
    printRange(-2, 10);
    */

    /*
    // TASK B:
    int x = sumRange(1, 3);
    cout << "This is " << x << endl;   // 6
    
    int y = sumRange(-2, 10);
    cout << "That is " << y << endl;   // 52
    */

    /*
    // TASK C:
    int size = 10;
    int *arr = new int[size]; // allocate array dynamically
    arr[0] = 12;
    arr[1] = 17;
    arr[2] = -5;
    arr[3] = 3;
    arr[4] = 7;
    arr[5] = -15;
    arr[6] = 27;
    arr[7] = 5;
    arr[8] = 13;
    arr[9] = -21;

    int sum1 = sumArray(arr, size); // Add all elements
    cout << "Sum is " << sum1 << endl;  // Sum is 43
    
    int sum2 = sumArray(arr, 5); // Add up first five elements
    cout << "Sum is " << sum2 << endl;  // Sum is 34

    delete[] arr;         // deallocate it
    */

    /*
    // TASK D:
    cout << isAlphanumeric("ABCD") << endl;        // true (1)
    cout << isAlphanumeric("Abcd1234xyz") << endl; // true (1)
    cout << isAlphanumeric("KLMN 8-7-6") << endl;  // false (0)
    */

    /*
    // TASK E:
    cout << nestedParens("((()))") << endl;      // true (1)
    cout << nestedParens("()") << endl;          // true (1)
    cout << nestedParens("") << endl;            // true (1)

    cout << nestedParens("(((") << endl;         // false (0)
    cout << nestedParens("(()") << endl;         // false (0)
    cout << nestedParens(")(") << endl;          // false (0)
    cout << nestedParens("a(b)c") << endl;       // false (0)
    */
    // TASK F:
    int prices [] = {10, 15, 12, 18, 19, 17, 13, 35, 33};
    int size = 9;

    cout << divisible (prices, size) << endl;
}

void printRange(int left, int right) {
    if(right < left) {
        cout << " ";
    } else if (left < right) {
        cout << left << " ";
        left++;
        printRange(left, right);
    } else {
        cout << right;
    }
}  

int sumRange(int left, int right) {
    int sum = 0;

    if(left <= right) {   
        sum = left;
        left++;
    } else {
        return sum;
    }

    return sum + sumRange(left, right);
}

int sumArray(int *arr, int size) {   
    int sum = 0;

    if(size > 0) {
        sum = arr[size - 1] + sumArray(arr, size - 1);
    }

    return sum;
}

bool isAlphanumeric(string s) {
    int a = s.size() - 1;

    if(a > 0 && isalnum(s[a])) {
        return isAlphanumeric(s.substr(0, a));
    }

    if(isalnum(s[a]) == false) {
        return false;
    }

    return true;
}

bool nestedParens(string s) {   
    int a = s.size() -1;

    if(s.size()==2 && s[0] == '(' && s[1] == ')' ) {
        return true;
    } else if (s.size() > 0) {   
        if(s[0] == '(' && s[a] == ')' && s.size() % 2 == 0) {
            return nestedParens(s.substr(1,a-1));
        } else {
            return false;
        }
    } 

    return true;
}

bool divisible(int *prices, int size) {
    if(sumArray(prices, size) % 2 == 0) {
        return true;
    }

    return false;
}