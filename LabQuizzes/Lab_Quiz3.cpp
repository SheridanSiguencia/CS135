//LabQuiz3.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab Quiz 3

Write a function: Greater of X or Y:
Enter two integers x and y,
print out the VALUE of the bigger number.

*/
#include <iostream>
using namespace std;



int main ()
{
    int x,y;

    cout << "Enter x ";
    cin >> x;

    cout << "Enter y ";
    cin >> y;

    if (x>y)
    {
        cout << x <<" X is greater";
    } else if (y>x){
        cout << y <<" Y is greater";
    }

    return 0;

}