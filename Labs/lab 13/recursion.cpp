//recursion.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: David Moncayo
Assignment: Lab 13F

In the same program, write a function:

bool divisible(int *prices, int size);
which returns true if the collection is divisible, 
and false otherwise. The prices are provided in the 
array prices, and size is the number of items in the array.
*/

#include <iostream>
#include <string>

using namespace std;

void printRange(int left, int right);
int sumRange (int left, int right);
int sumArray (int *arr, int size);
bool isAlphanumeric(std::string s);
bool nestedParens(string s);

bool divisible(int *prices, int size);


int main() 
{
    int prices [] = {10, 15, 12, 18, 19, 17, 13, 35, 33};
    int size = 9;

    cout << divisible (prices, size) << endl;
}

void printRange(int left, int right)
{
    if (right < left)
    {
        std::cout << " ";
    }
    else if (left < right)
    {
        std::cout << left << " ";
        left++;
        printRange(left, right);
    } else {
        std::cout << right;
    }
}

int sumRange(int left, int right)
{
    int sum=0;

    if (left <= right)
    {   
        sum = left;
        left++;

    } else{
        return sum;
    }

    return sum + sumRange(left, right);
}

int sumArray(int *arr, int size)
{   
    int sum = 0;

    if (size >0)
        sum = arr[size-1] +sumArray(arr, size-1);



    return sum;
}

bool isAlphanumeric(std::string s)
{
    int a = s.size()-1;
    
    if ( a> 0 && isalnum(s[a]))
        return isAlphanumeric(s.substr(0, a));
    
    if(isalnum(s[a]) == false)
        return false;


    return true;
}

bool nestedParens(string s)
{   
    int a = s.size() -1;
    if (s.size()==2 && s[0] == '(' && s[1] == ')' )
    {
        return true;
    }
    else if (s.size() > 0)
    {   
        if(s[0] == '(' && s[a] == ')' && s.size()%2==0 )
            return nestedParens(s.substr(1,a-1));
        else    
            return false;
    } 

    return true;
}

bool divisible(int *prices, int size)
{
    if ( sumArray(prices, size)%2 == 0)
        return true;

    return false;
}
