//optimism.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: David Moncayo
Assignment: Lab 12B


Make a program called optimism.cpp that implements the 
function vector<int> goodVibes(const & vector<int> v); 
that, given a vector of integers, returns a vector with 
only the positive integers in the same order.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> goodVibes(const vector<int> v);

int main ()
{
    vector<int> v{-1,-1,-1,-1,4,-1,-1};
    vector<int> ve = goodVibes(v);
    cout << "The vector size is " << ve.size() << endl;

    
    for(int i= 0; i < ve.size(); i++)
    {
        cout << ve[i] << " ";
    }
    return 0;
}

vector<int> goodVibes(vector<int> v)
{
    
    for(int i= 0; i < v.size(); i++)        
    {        
        if(v[i] <0)
        {
            v.erase(v.begin() + i);

            i--;
        }
    }
        
    return v;
}
