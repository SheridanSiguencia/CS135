//E7_18.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: Tong Yi
Assignment: E7.18

Define a structure Triangle that 
contains three Point members. 
Write a function that computes the 
perimeter of a Triangle. Write a program 
that reads the coordinates of the points, 
calls your function, and displays the result.
*/

#include <iostream>
#include <cmath>
using namespace std;


struct Point 
{
    double x;
    double y;
};

struct Triangle
{
    Point A;
    Point B;
    Point C;
};

double distance(Point p1, Point p2);

double perimeter( Triangle t);



int main()
{

    Triangle tri;

    cout<<"Enter coordinates for point 1: ";
    cin >> tri.A.x >> tri.A.y;

    cout<<"Enter coordinates for point 2: ";
    cin >> tri.B.x >> tri.B.y;

    cout<<"Enter coordinates for point 3: ";
    cin >> tri.C.x >> tri.C.y;

    //double per = perimeter(tri);

    
    cout << "The perimeter of the triangle is " << perimeter(tri);


    return 0;
}



double distance(Point p1x, Point p2)
{
    //use distance formula
    double side = pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2);
    
    return sqrt(side);
}

double perimeter(Triangle t)
{  
    
    double side1 = distance (t.A, t.B);
    double side2 = distance (t.A, t.C);
    double side3 = distance (t.B, t.C);

    return (side1 + side2 + side3);

} 
