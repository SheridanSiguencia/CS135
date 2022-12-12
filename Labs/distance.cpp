//E7_16.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: Tong Yi
Assignment: E7.16

Define a structure Point. 
A point has an x- and a y-coordinate. 
Write a function double distance(Point a, Point b) 
that computes the distance from a to b. 
Write a program that reads the coordinates 
of the points, calls your function, 
and displays the result.
*/

#include <iostream>
#include <math.h>
using namespace std;

struct Point{
    int x;
    int y;
};

double distance(Point a, Point b);


int main()
{
    Point A, B;

    cout<<"Enter coordinates for p1:";
    cin >> A.x >> A.y;

    cout<<"Enter coordinates for p2:";
    cin >> B.x >> B.y;
    double dis = distance(A, B);

    
    cout << "The distance between point A and B are " << dis;


    return 0;
}


double distance(Point a, Point b)
{
    //use distance formula
    double c = pow((b.x-a.x), 2) + pow((b.y-a.y), 2);
    
    return sqrt(c);
}