//3d-space.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: David Moncayo
Assignment: Lab 9E


Let’s implement it. In the same program, write a function

void move(Coord3D *ppos, Coord3D *pvel, double dt);
which gets the position and the velocity of an object 
and has to compute object’s new coordinates after the 
time interval dt. The function does not return any values, 
instead, it should update the object’s position ppos with 
its new position coordinates.

Because we pass the coordinates Coord3D * ppos as a pointer, 
all changes to the fields of the class pointed by ppos, will 
affect the original object you pass into the function, 
not its local copy.

*/

#include <iostream>
#include <cmath>

using namespace std;

class Coord3D {
public:
    double x;
    double y;
    double z;
};


double length(Coord3D *p);

void move(Coord3D *ppos, Coord3D *pvel, double dt);

// allocate memory and initialize
Coord3D* createCoord3D(double x, double y, double z);

// free memory
void deleteCoord3D(Coord3D *p);

int main()
{

    double x, y, z;
    cout << "Enter position: ";
    cin >> x >> y >> z;
    Coord3D *ppos = createCoord3D(x,y,z);
    
    cout << "Enter velocity: ";
    cin >> x >> y >> z;
    Coord3D *pvel = createCoord3D(x,y,z);

    move(ppos, pvel, 10.0);

    cout << "Coordinates after 10 seconds: " << (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << endl;

    deleteCoord3D(ppos); // release memory
    deleteCoord3D(pvel);

    return 0;
}

double length(Coord3D *p)
{
    //point distance formula 
    double value = pow((*p).x, 2) + pow((*p).y, 2) + pow((*p).z, 2);

    return sqrt(value);   
}

    
void move(Coord3D *ppos, Coord3D *pvel, double dt)
{

    ppos->x +=  pvel->x * dt;

    ppos->y += pvel->y * dt;

    ppos->z += pvel->z * dt;

}

// allocate memory and initialize
Coord3D* createCoord3D(double x, double y, double z)
{
    Coord3D *p = new Coord3D();
    p->x = x;
    p->y = y;
    p->z = z;

    return p;
}

// free memory
void deleteCoord3D(Coord3D *p)
{
    delete p;
}