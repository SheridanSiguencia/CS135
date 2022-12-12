/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project 1B

Write a program clac.cpp that reads from the cin a sequence of one or more non-negative integers written to be added or subtracted. Space characters can be anywhere in the input. After the input ends (end-of-file is reached), the program should compute and print the result of the input summation.
*/

//calc.cpp

#include <iostream>
using namespace std;


int main() {
  int sum= 0;
  int num;
  char sign;
  
  
  while (cin >> num) 
  {
    if (sign == '+') 
    {
      sum += num;
      
    } else if (sign == '-' )
    {
      sum -= num;
    }else {
      sum = num;
    }
    
    cin >> sign;

  }
  if (cin >> num){

  }
  cout << sum << endl;
  cout << "yo" << endl;
  return 0;
}
