// E6_8.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW E6_8

Write a function

bool equals(int a[], int a_size, int b[], int b_size)
that checks whether two arrays have the same elements
 in the same order.

*/


#include <iostream>
using namespace std;

bool equals(int a[], int a_size, int b[], int b_size);

int main ()
{
    cout << "Type array 1: ";
    int num1[] = {9, 8,4 ,6 ,5,5};

    cout << "Type array 2: ";
    int num2[] = {9, 8 , 4 , 6, 5, 5};

    int size1 = sizeof(num1)/sizeof(num1[0]);

    int size2 = sizeof(num2)/sizeof(num2[0]);

    bool same = equals(num1, size1, num2, size2);

    if (same == true)
    {
        cout << "\nYes they are the same";
    } else {
        cout << "No they are not the same";
    }
    return 0;
}    

bool equals(int a[], int a_size, int b[], int b_size)
{
    if (a_size == b_size)
    {
        for (int i = 0; i < a_size ; i++)
        {
            if (a[i] != b[i])
            {
                return false;
            } 
        }
    } else {
        return false;
    }
    
    return true;
}