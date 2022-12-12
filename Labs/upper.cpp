//upper.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: David Moncayo
Assignment: Lab 4D

Write a program upper.cpp that 
prints the top-right half of a 
square, given the side length.
*/

#include <iostream>
using namespace std;

int main() 
{
    int size;

    cout << "Input size: ";
    cin >> size;
    //string gap = "+";

    cout << endl <<"Shape:" <<endl;

    
    for ( int row=1; row <= size; row++)
    {   
        for (int col = 1; col <=size; col++) 
        {   
            if (row <= col ) {
                cout <<"*";
            } else {
                cout << " ";    
            }

        }

        cout << endl;
    }
    
   return 0; 

}