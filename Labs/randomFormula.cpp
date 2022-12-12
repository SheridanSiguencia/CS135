#include <iostream>
#include <string>
using namespace std;

int main ()
{
// rand()% (max- min + 1) + start
  int a = rand() % (300 +1 -100) -100;
  

  cout << "random number is " << a;

   return 0;

}