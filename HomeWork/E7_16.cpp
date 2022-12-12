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

struct Point{
    double x;
    double y;
};

double distance(Point a, Point b);


int main()
{
    Point A, B;

    std::cout<<"Enter coordinates for p1:";
    std::cin >> A.x >> A.y;

    std::cout<<"Enter coordinates for p2:";
    std::cin >> B.x >> B.y;

    
    std::cout << "\nThe distance between point A and B are " << distance(A, B) << std::endl;

    distance(A,B);


    return 0;
}


double distance(Point a, Point b)
{
    //use distance formula
    double xs = pow((b.x-a.x), 2); 
    double ys = pow((b.y-a.y), 2);
    
    return sqrt(xs + ys);
}