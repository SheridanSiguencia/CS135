//box.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: David Moncayo
Assignment: Lab Quiz6

Write a program box.cpp that 
asks the user to input width and height 
and prints a solid rectangular box of the requested 
size using asterisks.

Also, print a line Shape: between user input and the 
printed shape (to separate input from output).

*/

#include <iostream>
using namespace std;



int main() 
{
    int w, h;

    cout << "Input width: ";
    w= 5;

    cout << "Input height: ";
    h= 6;

    cout << endl <<"Shape:" <<endl;

    while (h>0)
    {
        for (int i=0; i < w; i++)
        {
            cout << "*";
        }
        cout<<endl;
        h--;
    } 




}