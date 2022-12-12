// E5_15.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW E5.15

Write a function sort3(int& a, int& b, int& c)
that swaps its three arguments to arrange them
in sorted order.
*/

#include <iostream>
using namespace std;

void sort2 ( int& a, int& b)
{
    int vessel;
    if (a > b)
    {
        vessel = b;
       
        b = a; 

        a= vessel;
        
    }  else {
        a=a;

        b=b;
    } 
}


void sort3 (int& a , int& b, int&c)
{   
    //if a is less than b, then nothing. However if 'a' is bigger switch etc
    sort2(a,b);
    
    sort2(a,c);

    sort2(b,c);
}


int main() 
{
    int a,b,c;

    cout << "Enter number 'a': "; 
    cin >> a;

    cout << "Enter number 'b': ";
    cin >> b;

    cout << "Enter number 'c': ";
    cin >> c;


    sort3(a, b, c);

    cout << "Chronological order " << a << ", " << b << ", " << c;
    return 0;


}