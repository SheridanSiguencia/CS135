//numbers.cpp
//largestTwinPrime.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: David Moncayo
Assignment: Lab 5G

Add a function

int largestTwinPrime(int a, int b);
that returns the largest twin prime in the range a ≤ N ≤ b.
If there is no twin primes in range, then return -1.

For example:
largestTwinPrime(5, 18) == 17
largestTwinPrime(1, 31) == 31
largestTwinPrime(14, 16) == -1
Change the main function to test the new code.

*/

#include <iostream>
#include <climits>
#include <cmath>
using namespace std;


bool isDivisibleBy (int n, int d) 
{

    if (d == 0)
    {
        return (false);

    } else if (n % d == 0){

        return (true);

    } else {
        return (false);
    }
}

bool isPrime (int n) 
{

    if (n < 2)
    {
        return false;
    } 

    for (int i = 2; i < n; i++)
    {
        if (isDivisibleBy(n,i))
        {
            return false;
        }
    }
    return true;

}

int nextPrime (int n)
{

    for (int i = n+1; i < INT_MAX; i++  )
    {
        if ( isPrime(i) == true)
        {
        return(i);
        }
    }
    return (0);
}

int countPrimes (int a, int b)
{
    int tally=0;

    for (int i = a; i <= b; i++  )
    {

        if ( isPrime(i) == true)
        {
            tally ++;
        }
    }

    return tally;
}

bool isTwinPrime( int n)
{
    if (isPrime(n)== false)
    {
        return false;

    } else if ( isPrime(n-2) || isPrime(n+2)) {
        return true;
    }

    return false;
}

int nextTwinPrime(int n)
{
    for (int i=n+1; i <INT_MAX; i++)
    {   if (isTwinPrime(i)== true)
        {
            return (i);
        }
    }
}

int largestTwinPrime (int a, int b)
{

    for (int i = b; i >= a; i--)
    {

        if ( isTwinPrime(i))
        {
            return i;
        }
    }

    return -1;
}

int main() 
{
    
    int num1, num2;
    cout << "Enter a 2 positive integer interval: \n";
    cin >> num1;
    cin >> num2;

    int largest = largestTwinPrime(num1, num2);

    cout << "The largest twin prime in the range from " << num1 << " to " << num2 << " is " << largest;
    
    return 0;
}

