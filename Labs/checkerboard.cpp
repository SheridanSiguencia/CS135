//checkerboard.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: David Moncayo
Assignment: Lab 4B

Write a program checkerboard.cpp that 
asks the user to input width and height
and prints a rectangular checkerboard of 
the requested size using asterisks and spaces (alternating).

Example:

Also, print a line Shape: between user input and the 
printed shape (to separate input from output).

*/

#include <iostream>
using namespace std;




int main() 
{
    int w, h;

    cout << "Input width: ";
    cin >> w;

    cout << "Input height: ";
    cin >> h;

    cout << endl <<"Shape:" <<endl;


    for (int row = 0; row < h; row++) 
    {   
       
        
        for (int col = 0; col < w; col++) 
        {
            if ((row %2)== 0)
            {

                if (col % 2 == 0)
                {
                cout << "*";
                } else {
                cout << " ";
                } 


            } else {
                 if (col % 2 == 0)
                {
                cout << " ";
                } else {
                cout << "*";
                } 
            }
        }
        cout << endl;
    }




}