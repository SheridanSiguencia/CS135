// E5_14.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW E5.14

Write a function void sort2(int& a, int& b) 
that swaps the values of a and b if a is greater 
than b and otherwise leaves a and b unchanged.
*/

#include <iostream>
using namespace std;

void sort2 ( int& a, int& b)
{
    int c;
    if (a > b){
        c = b;
       
        b = a; 
        
        a= c;
    }  else {
    
    } 
}

int main() 
{
    int a,b;

    cout << "Enter two numbers: "; 
    cin >> a;

    cout << " and ";
    cin >> b;

    sort2(a, b);

    cout << "a is " << a << " and b is " << b;
    return 0;


}