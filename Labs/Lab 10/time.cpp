/*
Author: Isaac Lal
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Lab 10A, 10B, 10C, 10D, 10E

TASK A:
Create a new program time.cpp. (Copy the class Time declaration in your program, it should be placed before main() function.)

Implement two new functions:

int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);
The first function should return the number of minutes from 0:00AM until time.

The second function should receive two Time arguments earlier and later and report how many minutes separate the two moments. For example, when passing 10:30AM and 1:40PM:

minutesUntil( {10, 30}, {13, 40} )  
// ==> should return 190 minutes
(A caveat: If the earlier moment of time happens to be after the later moment of time, report a negative number of minutes. Although it’s not difficult to achieve this if your 
implementation for the first function is correct.)

For testing purposes, implement a simple user interface:

$ ./time
Enter first time:  10 30
Enter second time: 13 40

These moments of time are X and Y minutes after midnight.
The interval between them is Z minutes.


TASK B:
Add a new function to your program time.cpp:

Time addMinutes(Time time0, int min);
The function should create and return a new moment of time that is min minutes after time0. Example:

addMinutes({8, 10}, 75)
// ==> should return {9, 25}
(We will not test how your function behaves if the new returned time will be on the next day, feel free to assume that it will remain withing the same day, ≤ 23:59.)

Adjust the main function for testing this function. Feel free to add additional tests to check the correctness of your code.


TASK C: 
In the same program time.cpp, implement your own printing function printTimeSlot(TimeSlot ts). It should make output in the following format:

Back to the Future COMEDY (116 min) [starts at 9:15, ends by 11:11]
The ending time is the starting time + movie duration.

Write main function that defines at least five time slots

morning, daytime, and evening defined previously,
plus add a couple of your own time slots with some of your favorite movies (their duration time can be found in IMDB).
The program output should look like:

$ ./time
Back to the Future COMEDY (116 min) [starts at 9:15, ends by 11:11]
Black Panther ACTION (134 min) [starts at 12:15, ends by 14:29]
Black Panther ACTION (134 min) [starts at 16:45, ends by 18:59]
 -- your time slot #1 --
 -- your time slot #2 --
 --        ...        --
When defining your own time slots, please make sure they end before midnight, 23:59, so the ending time does not show the next day.


TASK D:
Add a new function

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);
The function should produce and return a new TimeSlot for the movie nextMovie, scheduled immediately after the time slot ts.

For example, if the movie scheduled in ts starts at 14:10 and lasts 120 minutes, then the time slot for the next movie should start at exactly 16:10.

Modify main function to test your code.


TASK E:
Add a new function

bool timeOverlap(TimeSlot ts1, TimeSlot ts2); 
The function should return true if the two time slots overlap, otherwise return false. (Take into account the starting times of the time slots and the duration of the scheduled movies.)

Modify main function to test your code.

Hint: You may use minutesUntil to check which time slot is earlier, then find the how long is the interval between their starting times. They overlap if the movie duration is greater than the 
interval between the time slots’ starting times. Alternatively, converting times into minutes since midnight can be a good idea as well.

(By the way, if you want to be accurate, if one movie starts at 10:00 and lasts 90 minutes until 11:30, then it does not overlap with a movie that starts exactly at 11:30. However, they would overlap 
if the latter movie started one minute earlier, at 11:29.)
*/

#include <iostream>

// Classes & Enums
class Time {
public: 
    int h;
    int m;
};

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

class Movie { 
public: 
    std::string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};

class TimeSlot { 
public: 
    Movie movie;     // what movie
    Time startTime;  // when it starts
};

// Function Names
int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);
Time addMinutes(Time time, int min);
void printMovie(Movie mv);
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);
bool timeOverlap(TimeSlot ts1, TimeSlot ts2); 

// Main
int main() {
    /* 
    // TASK A:
    Time time1, time2;

    std::cout << "Enter first time: ";
    std::cin >> time1.h >> time1.m;
    std::cout << "Enter second time: ";
    std::cin >> time2.h >> time2.m;

    std::cout << "\n" << "These moments of time are X and Y minutes after midnight." << "\n";
    std::cout << "The interval between them is Z minutes.";
    */

    /* 
    // TASK B:
    Time time, addedTime;
    std::cout << "Enter first time: ";
    std::cin >> time.h >> time.m;

    addedTime = addMinutes(time, 75);
    std::cout << addedTime.h << ":" << addedTime.m << "\n";
    */

    /* 
    // TASK C:
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", THRILLER, 134};
    Movie movie3 = {"Avengers", ACTION, 200};
    Movie movie4 = {"Inception", DRAMA, 148};
    Movie movie5 = {"Titanic", ROMANCE, 194};

    TimeSlot morning = {movie1, {9, 15}};  
    TimeSlot daytime = {movie2, {12, 15}}; 
    TimeSlot daytime2 = {movie1, {14, 25}};
    TimeSlot afternoon = {movie3, {15, 45}};
    TimeSlot afternoon2 = {movie4, {17, 35}};
    TimeSlot evening = {movie2, {16, 45}}; 
    TimeSlot night = {movie5, {20, 55}};
    */

    /* 
    // TASK D:
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    TimeSlot morning = {movie1, {9, 15}};  

    TimeSlot nextTimeSlot = scheduleAfter(morning, movie1);
    */

    // TASK E:
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", THRILLER, 134};
    TimeSlot daytime = {movie2, {12, 15}}; 
    TimeSlot daytime2 = {movie1, {14, 25}};
    std::cout << timeOverlap(daytime, daytime2) << std::endl;
}

// Program Functions
int minutesSinceMidnight(Time time) {
    int mins = (time.h * 60) + time.m;

    return mins;
}

int minutesUntil(Time earlier, Time later) {
    int mins = (later.h - earlier.h) * 60 + (later.m - earlier.m);

    return mins;
}

Time addMinutes(Time time, int min) {
    Time newTime;

    newTime.h = time.h + (time.m + min) / 60;
    newTime.m = (time.m + min) % 60;

    return newTime;
}

void printMovie(Movie mv) {
    std::string g;

    switch (mv.genre) {
        case ACTION: 
            g = "ACTION"; 
            break;
        case COMEDY: 
            g = "COMEDY"; 
            break;
        case DRAMA: 
            g = "DRAMA";  
            break;
        case ROMANCE: 
            g = "ROMANCE"; 
            break;
        case THRILLER: 
            g = "THRILLER"; 
            break;
    }

    std::cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

void printTimeSlot(TimeSlot ts) {
    Time endingTime = addMinutes(ts.startTime, ts.movie.duration);
    
    printMovie(ts.movie);

    std::cout << "[starts at " << ts.startTime.h << ":" << ts.startTime.m 
              << ", ends by " << endingTime.h << ":" << endingTime.m << "]" << "\n";
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie) {
    TimeSlot nextTimeSlot;
    nextTimeSlot.movie = nextMovie;
    nextTimeSlot.startTime = addMinutes(ts.startTime, ts.movie.duration);

    return nextTimeSlot;
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2) {
    if(minutesSinceMidnight(ts1.startTime) < minutesSinceMidnight(ts2.startTime)) {
        return ts1.movie.duration > (minutesSinceMidnight(ts2.startTime) - minutesSinceMidnight(ts1.startTime));
    } else {
        return ts2.movie.duration > (minutesSinceMidnight(ts1.startTime) - minutesSinceMidnight(ts2.startTime));
    }
}