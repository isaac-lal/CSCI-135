/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab Quiz 10

Format Date

Define a function, formatDate, that returns the formatted date string given a pointer
to a Date object:

string formatDate(Date *d);

You may use the function to_string() to convert an integer to a string. Make sure
Date is defined in your program
*/

#include <iostream>
using namespace std;

string formatDate(Date * d);

class Date {
public:
    int month;
    int day;
    int year;
};

int main() {
    Date midterm1 = Date {10, 17, 2022};
    cout << formatDate(&midterm1) << endl;

    Date christmas = Date {12, 25, 2022};
    cout << formatDate(&christmas) << endl;
}

string formatDate(Date * d) {
    string monthName;

    if(d -> month == 1) {
        monthName = "Jan";
    } else if(d -> month == 2) {
        monthName = "Feb";
    } else if(d -> month == 3) {
        monthName = "Mar";
    } else if(d -> month == 4) {
        monthName = "Apr";
    } else if(d -> month == 5) {
        monthName = "May";
    } else if(d -> month == 6) {
        monthName = "June";
    } else if(d -> month == 7) {
        monthName = "July";
    } else if(d -> month == 8) {
        monthName = "Aug";
    } else if(d -> month == 9) {
        monthName = "Sep";
    } else if(d -> month == 10) {
        monthName = "Oct";
    } else if(d -> month == 11) {
        monthName = "Nov";
    } else if(d -> month == 12) {
        monthName = "Dec";
    } 

    return monthName + " " + to_string(d -> day) + ", " + to_string(d -> year);
}