//time.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: David Moncayo
Assignment: Lab 10C

In the same program time.cpp, 
implement your own printing function 
printTimeSlot(TimeSlot ts). 
It should make output in the following format:

Back to the Future COMEDY (116 min) 
[starts at 9:15, ends by 11:11]
The ending time is the starting time + movie duration.
*/

#include <iostream>

using namespace std;

// make my lists of constants 
enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

class Time 
{
public:
    int h;
    int m;

};


class Movie 
{ 
public: 
    string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};


class TimeSlot 
{ 
public: 
    Movie movie;     // what movie
    Time startTime;  // when it starts
};

//fucntions for program
void printTime (Time time);
void printMovie(Movie mv);
void printTimeSlot(TimeSlot ts);

int minutesSinceMidnight (Time time);
int minutesUntil (Time earlier, Time later);
Time addMinutes(Time time0, int min);

int main ()
{   
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", ACTION, 134};
    Movie movie3 = {"Ice Age", COMEDY, 81};

    Time a = {9, 15};
    Time b = {12, 15};
    Time c = {11, 15};
    Time d = {16, 45};
    Time e = {14, 30};


    TimeSlot morning = {movie1, a};  
    TimeSlot daytime = {movie2, b}; 
    TimeSlot afternoon= {movie3, c};    
    TimeSlot evening = {movie2, d}; 
    TimeSlot nighttime= {movie3, e};

    printTimeSlot(morning);
    printTimeSlot(daytime);
    printTimeSlot(afternoon);
    printTimeSlot(evening);
    printTimeSlot(nighttime);

    return 0;
}

//printing functions
void printTime(Time time) 
{
    cout << time.h << ":" << time.m;
}

void printMovie(Movie mv)
{
    string g;
    switch (mv.genre) 
    {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

void printTimeSlot(TimeSlot ts)
{

    printMovie(ts.movie);
    cout <<  " [starts at ";
    printTime(ts.startTime);
    cout << ", ends by ";
    printTime(addMinutes(ts.startTime, ts.movie.duration)); 
    cout << "]" << endl;

}


//other functions
int minutesSinceMidnight (Time time)
{
    time.m += time.h * 60;
    
    return time.m;
}

int minutesUntil (Time earlier, Time later)
{
    int e = minutesSinceMidnight (earlier);

    int l = minutesSinceMidnight (later);

    return (l-e);

}

Time addMinutes(Time time0, int min)
{
    time0.m += min;

    while (time0.m >= 60)
    {
        time0.h++;
        time0.m -= 60;
    }

    return time0;
}


