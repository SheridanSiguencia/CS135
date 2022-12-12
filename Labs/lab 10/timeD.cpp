//time.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: David Moncayo
Assignment: Lab 10D

Add a new function
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);

The function should produce and return a new TimeSlot 
for the movie nextMovie, scheduled immediately after 
the time slot ts.


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
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);

int main ()
{   
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", ACTION, 134};
    Movie movie3 = {"Ice Age", COMEDY, 81};

    Time a = {9, 15};

    TimeSlot time1 = {movie1, a};  
    
    printTimeSlot(time1);

    TimeSlot time2= scheduleAfter(time1, movie2);

    printTimeSlot(time2);

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

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie)
{
    TimeSlot nextSlot;
    nextSlot = {{nextMovie}, {addMinutes(ts.startTime, ts.movie.duration)}};

    return nextSlot;
}

