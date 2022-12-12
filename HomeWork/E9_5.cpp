// E9_5.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW E9.5

Implement a class Rectangle. 
Provide a constructor to construct a rectangle 
with a given width and height, member functions 
get_perimeter and get_area that compute the perimeter 
and area, and a member function void resize(double factor) 
that resizes the rectangle by multiplying the width 
and height by the given factor.
*/

#include <iostream>

using namespace std;

class Rectangle 
{
private:
    double width;
    double height;

public:
    Rectangle();
    Rectangle(double w, double h);
    double get_perimeter();
    double get_area();

    void resize(double factor);

};

Rectangle::Rectangle()
{
    width= 0;
    height=0;
}

Rectangle::Rectangle(double w, double h)
{  
    width = w;
    height = h;
}

double Rectangle::get_perimeter()
{
    return (2*width + 2*height);

}

double Rectangle::get_area()
{
    return(width*height);
}

void Rectangle::resize(double factor)
{
    width *= factor;
    height *= factor;  
}

int main ()
{
    Rectangle r = {2, 4};
    
    
    cout << "Perimeter is " << r.get_perimeter() << endl;
    cout << "Area is " << r.get_area() << endl;

    r.resize(3);

    cout << "Perimeter is " << r.get_perimeter() << endl;
    cout << "Area is " << r.get_area() << endl;

}