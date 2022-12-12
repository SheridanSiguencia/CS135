//Lab_Quiz9.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab Quiz 9

Lab Quiz 09 - Date 
Define class Date 
with public data members year, month, 
day as int and day_of_week as string. 
Define 
printDate(Date *input) prints day_of_week, month/day/year. 
12/6/2021, Monday, is printed "Monday, 12/6/2021".
*/

#include <iostream>
#include <string>

using namespace std;

class Date{
public:
    int year;
    int month;
    int day;
    string day_of_week;

};

void printDate(Date * input);

int main()
{
    Date d;
    cout << "Enter year month and day: ";
    cin >> d.year >> d.month >> d.day;

    cout << "Enter day of the week: ";
    cin >> d.day_of_week;
    
    printDate(&d);
    return 0;
}

void printDate (Date * input)
{
    cout << input->day_of_week<< ", " << input->month << "/" << input->day << "/" << input->year << endl;


}