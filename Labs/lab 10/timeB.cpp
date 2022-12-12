//time.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: David Moncayo
Assignment: Lab 10B


Add a new function to your program time.cpp:
Time addMinutes(Time time0, int min);

The function should create and 
return a new moment of time that 
is min minutes after time0
*/

#include <iostream>

using namespace std;

class Time 
{
public:
    int h;
    int m;

};


//fucntions for program
void printTime (Time time);

int minutesSinceMidnight (Time time);

int minutesUntil (Time earlier, Time later);

Time addMinutes(Time time0, int min);

int main ()
{   

    Time a = {8,10};
    int m = 75;


    printTime(addMinutes (a,m));

    

    
    return 0;
}

void printTime(Time time) 
{
    cout << time.h << ":" << time.m;
}

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
