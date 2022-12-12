//Lab_Quiz7.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab Quiz 7

Lab Quiz 07 - define function 
`int max3(int a, int b, int c)` 
that returns the maximum of a, b, and c.
*/
#include <iostream>
using namespace std;


int max3(int a, int b, int c)
{
    if (a>b && a>c)
    {
        return a;
    } else if (b>c){
        return b;
    } else {
        return c;
    }
}

int main ()
{
    int x,y, z;

    cout << "Enter x ";
    cin >> x;

    cout << "Enter y ";
    cin >> y;
    
    cout << "Enter z ";
    cin >> z;

    int max = max3( x, y , z);
    if (max == x)
    {
        cout << x <<" X is greatest";
    } else if (max == y){
        cout << y <<" Y is greatest";
    } else {
        cout << z << "Z is greatest";
    }

    return 0;

}