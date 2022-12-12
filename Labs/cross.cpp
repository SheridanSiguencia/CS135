//cross.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: David Moncayo
Assignment: Lab 4C

Write a program cross.cpp that asks 
the user to input the shape size, and 
prints a diagonal cross of that dimension.


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
            if (row == col || col == (size+1)-row) {

            
                cout <<"*";
            } else {
                cout << " ";    
            }

        }

        cout << endl;
    }
    
   return 0; 

}