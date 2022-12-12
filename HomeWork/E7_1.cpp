//E7_1.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: Tong Yi
Assignment: E7.1

Write a function

void sort2(double* p, double* q)
that receives two pointers and sorts the values
 to which they point. If you call

sort2(&x, &y)
then x <= y after the call.

*/
#include <iostream>
using namespace std;

void sort2 (double* p, double* q);


int main ()
{
    double x, y;
    cout << "x is ";
    cin >> x;

    cout << "y is ";
    cin >> y;

    
    sort2(&x, &y);

    cout << "x is " << x << " and y is " << y;



}

void sort2 (double* p, double* q)
{   
    //have to use * to adress change
    if (*p > *q)
    {
        double temp = *p;
        *p= *q;
        *q= temp;
    }
    return;
}
