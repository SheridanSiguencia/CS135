#include <iostream>
using namespace std;

int main() {
  int sum = 0;
  int sqr;
  int num;
  char sign = '+';

  
  while (cin >> num) 
  {
    if (sign == '^'){
        cin >> sign;
        sum = num *num;
        cin.putback(num);
    }   

    if (sign == '+' )
    {
      sum += num;
    } 
    else if (sign == '-')
    {

      sum -= num;
    }

    cin >> sign;
    
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