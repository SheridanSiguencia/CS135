//Lab_Quiz12.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab Quiz 12

Lab Quiz 12 - Money 
Define class Money with public 
int data members dollars and cents. Define NON member 
\function Money add_money(Money x, Money y) where cents 
of added result is < 100.
*/

#include <iostream>
using namespace std;

class Money 
{
public:    //data members
    int dollars;
    int cents;
    
};

Money add_money(Money x, Money y);

int main()
{   
    
    string str= "yo";
    //create data of money 
    Money m1= {4, 20};
    Money m2= {6, 90};

    //sum
    Money sum = add_money(m1, m2);
    cout << "The sum is $" << sum.dollars << "." << sum.cents ;
    
    return 0;
}

Money add_money(Money x, Money y)
{   
    x.cents += y.cents;
    

    //if higher or equal to 100 subtracts 100 til if under and adds one to dollars
    while (x.cents >= 100)
    {   
        x.cents -= 100;
        x.dollars++;
    }   

    x.dollars += y.dollars;

    return {x.dollars, x.cents};
    
}



