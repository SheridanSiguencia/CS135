//vectors.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: David Moncayo
Assignment: Lab 12A

A big benefit of vectors is their ability 
to be returned from functions. 

For this task, 
program a function called vector<int> makeVector(int n) 
that returns a vector of n integers that range from 0 to n-1. 
Call your program vectors.cpp. Your function must be 
implemented outside the main function and must return a vector.

*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> makeVector (int n);

int main ()
{
    int a;
    cout << "Enter a number ";
    cin >> a;

    vector<int> av = makeVector(a);
    cout << "The vector size is " << av.size() << endl;
    for(int i= 0; i < av.size(); i++)
    {
        cout << av[i] << " ";
    }
}

vector<int> makeVector (int n)
{
    vector<int> temp;
    if (n >0)
    {   
        for(int i= 0; i < n; i++)        
            temp.push_back(i);

        return temp;
    }
    return temp;
}

