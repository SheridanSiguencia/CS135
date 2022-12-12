//time.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: David Moncayo
Assignment: Lab 10E

Add a new function
bool timeOverlap(TimeSlot ts1, TimeSlot ts2); 

The function should return true if the two 
time slots overlap, otherwise return false. 
(Take into account the starting times of the time 
slots and the duration of the scheduled movies.)


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
bool timeOverlap(TimeSlot ts1, TimeSlot ts2); 

int main ()
{   
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", ACTION, 134};
    Movie movie3 = {"Ice Age", COMEDY, 81};

    Time a = {9, 15};
    Time b = {11, 10};
    TimeSlot time1 = {movie1, a};  
    TimeSlot time2 = {movie2, b};
    printTimeSlot(time1);

    printTimeSlot(time2);

    if (timeOverlap(time1,time2)==true)
        cout << "These times overlap\n";
    else    
        cout << "These times do not overlap\n";

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

bool timeOverlap(TimeSlot ts1, TimeSlot ts2)
{

    // if this is true then ts1 is earlier than ts2 and if its equal then it doesn't matter which one 
    if (minutesUntil (ts1.startTime, ts2.startTime)>0)
    {   
        
        //this the the end time of the earlier movie comparing to the start time 
        if (minutesUntil((addMinutes(ts1.startTime, ts1.movie.duration)), ts2.startTime) < 0)
            return true;
    }else{
        //this happens if ts2 is earlier
        if (minutesUntil(addMinutes(ts2.startTime, ts2.movie.duration), ts1.startTime) < 0)
            return true;
    }
    
    return false;

}
