//calc3.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project 1D

Write an even better calculator program calc3.cpp that can understand squared numbers. We are going to use a simplified notation X^ to mean X2.
*/

#include <iostream>
using namespace std;

int main() {
  int sum = 0;
  int num=0 ;
  char sqared;

  char sign = '+';
  cin >>num;
  
  while (cin >> sqared) 
  {
    if (sqared == '^'){
        num *= num;
        cin >> sqared;
    }   

    if (sign == '+' )
    {
      sum += num;
    } 
    else if (sign == '-')
    {

      sum -= num;
    }

    sign = sqared;
    cin >> num;

    if (sign == ';')
      {
      sum = sum;
      cout << sum << endl;
      sign = '+';
      sum =0;
      }
  }

  return 0;
}
// calc3.cpp