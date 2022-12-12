//checkerboard3x3.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: David Moncayo
Assignment: Lab 4G

Write a program checkerboard3x3.cpp 
that asks the user to input width and 
height and prints a checkerboard of 3-by-3 squares. 
(It should work even if the input dimensions 
are not a multiple of three.)

*/

#include <iostream>
using namespace std;




int main() 
{
    int w, h;
    int star = 0;
    int space = 0;

    cout << "Input width: ";
    cin >> w;

    cout << "Input height: ";
    cin >> h;

    cout << endl <<"Shape:" <<endl;


	
	for(int row = 0; row < h; row++)
	{
		for(int col = 0; col < w; col++)
		{
			if( (col%6 < 3 && row%6 < 3) || (col%6 >= 3 && row%6 >= 3) )
			{
				if(star < 3)
				{
					cout << "*";
				}

				star++; 
                //reset
				if(star == 3)
				{
					star = 0;
				}
			}	

			else
			{
				if(space < 3)
				{
					cout << " ";
				}
				space++;

				if(space == 3)
				{
					space = 0;
				}
			}
		}

		cout << endl;
	}	
    return 0;
}