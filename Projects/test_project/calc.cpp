#include <iostream>
#include "calculations.hpp"
using namespace std;

int main ()
{
    int a = 9;
    int b = 3;

    cout << "Addition of a + b is  ";
    add(a,b);

    cout << "subtraction of b - a is ";
    sub(b,a);

    return 0;
}