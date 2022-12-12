// calc2.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project 1C

Write a program calc2.cpp that calculates the sum of the line individually after semi-colon
*/

#include <iostream>
using namespace std;

int main() {
  int sum= 0;
  int num;
  char sign='+';
  
  
  while (cin >> num) 
  {
    if (sign == '+') 
    {
      sum += num;
      
    } else if (sign == '-' )
    {
      sum -= num;
    }
    cin >> sign;
    
    //distinguishes the end to start a fresh sum
    if (sign == ';'){
      cout << sum << endl;
      sign = '+';
      sum = 0;

    }
  }
  return 0;
  
  
}