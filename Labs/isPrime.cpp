//isPrime.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: David Moncayo
Assignment: Lab 5B

A prime number is an integer greater or equal to 2 that is only divisible by 1 and by itself.
 The first few primes are: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 …

N is a prime if and only if it is not divisible evenly by any of the numbers from 
2 to N−1. Let’s implement this decision as a function.

In the same program numbers.cpp, add a function

bool isPrime(int n);
The function should return true if n is a prime,
 otherwise return false. Change the main function to test your new code.

*/

#include <iostream>
#include <cmath>
using namespace std;



bool isPrime (int n) 
{

    int counter;

    if (n < 2)
    {
        return false;

    } 

    for (int i =1; i <= n; i++)
    {
        if (n%i == 0)
        {
            counter ++;
        }

    }

    if (counter != 2)
    {    
        return false;
    }  else {
        return true;
    }  


}

int main() 
{
    int num;
    

    cout << "Enter a positive integer to test if it is a prime: ";
    cin >> num;

    bool test= isPrime (num);

    cout << "Is " << num << " a prime? \n";
    if ( test== true)
    {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}

