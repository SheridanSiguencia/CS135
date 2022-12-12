//E6_18.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW E6.18


Write a function

vector<int> append(vector<int> a, vector<int> b)
that appends one vector after another. 
For example, if a is
1 4 9 16

and b is
9 7 4 9 11

then append returns the vector
1 4 9 16 9 7 4 9 11
*/

#include <iostream> 
#include <vector>
using namespace std;


vector<int> append(vector<int> a, vector<int> b);

int main()
{
    vector<int> a= {1, 4, 9, 16};
    vector<int> b= {9, 7, 4, 9, 11};
    for (int i= 0; i < a.size(); i++)
        cout << a[i] << " ";

    vector<int> c= append(a,b);
    cout << endl;

    for (int i= 0; i < c.size(); i++)
        cout << c[i] << " ";

    return 0;
}

vector<int> append(vector<int> a, vector<int> b)
{
    
    for (int i=0; i<b.size(); i++)
        a.push_back(b[i]);

    return a;
}