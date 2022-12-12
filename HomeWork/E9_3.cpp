// E9_3.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW E9.3

Simulate a circuit for controlling a hallway 
light that has switches at both ends of the 
hallway. Each switch can be up or down, and 
the light can be on or off.Toggling either 
switch turns the lamp on or off.
*/

#include <iostream>
using namespace std;

class Circuit
{
private:
    int first;
    int second;

public:
    Circuit();
    int get_first_switch_state(); // 0 for down, 1 for up
    int get_second_switch_state(); // same thing as first
    int get_lamp_state(); // 0 for off, 1 for on
    void toggle_first_switch();//flick
    void toggle_second_switch();
};

int main ()
{
    Circuit c;

    cout << "The switch is "<< c.get_first_switch_state()<< endl;
    cout << "The swith is "<< c.get_second_switch_state()<< endl;

    cout << "The light is "<< c.get_lamp_state()<< endl;


    c.toggle_first_switch();

    cout << "The light is "<< c.get_lamp_state()<< endl;

    c.toggle_second_switch();

    cout << "The light is "<< c.get_lamp_state()<< endl;
    
    c.toggle_first_switch();

    cout << "The light is "<< c.get_lamp_state()<< endl;

    c.toggle_second_switch();

    cout << "The light is "<< c.get_lamp_state()<< endl;


}

Circuit::Circuit()
{
    first = 0;
    second =0;
}

int Circuit::get_first_switch_state() // 0 for down, 1 for up
{   

    
    return first;

}

int Circuit::get_second_switch_state()
{
    return second;
}

int Circuit::get_lamp_state() // 0 for off, 1 for on
{
    

    if (first!=second)
        return 1;
        

    return 0;
}

void Circuit::toggle_first_switch()
{
    first ++;
    first= first%2;    
}

void Circuit::toggle_second_switch()

{
    second ++;
    second= second%2;
}