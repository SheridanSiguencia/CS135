//trapezoid.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: David Moncayo
Assignment: Lab 4F

Write a program trapezoid.cpp that 
prints an upside-down trapezoid of 
given width and height.

However, if the input height is 
impossibly large for the given width, 
then the program should report, Impossible shape!
*/

#include <iostream>
using namespace std;

int main () 
{
    int w, h;

    cout << "Input width: ";
    cin >> w;

    cout << "Input height: ";
    cin >> h;

    if ( w <= (2*h)-2)
    {
        cout << "Impossible shape!";
        return 0;
    }

    cout << endl <<"Shape:" <<endl;

    for ( int row=1; row <= h; row++)
    {   
        for (int col = 1; col <= w; col++) 
        {   
            

            if (row <= col && row <= (w-col)+1 )
            {
                cout <<"*";
            } else {
                cout << " ";    
            }
               
        }

        cout << endl;
    }
    
   return 0; 

}