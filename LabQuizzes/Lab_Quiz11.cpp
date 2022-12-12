//Lab_Quiz11.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab Quiz 11


Lab Quiz 11 - create a 
checkerboard image
*/

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>

using namespace std;


int main()
{
    int img[MAX_H][MAX_W];
    int h,w;

    readImage(img, h, w);
    int out[MAX_H][MAX_W];

    for(int row = 0; row < h; row++)
    {
        for (int col = 0; col < w; col++)
        {
            if ((row %2)== 0)
            {
                if (col % 2 == 0)
                {
                    out[row][col] = 0;
                }else {
                    out[row][col] = img[row][col];
                } 
            }
            else
            { 
                if (col % 2 == 0)
                {
                    out[row][col] = img[row][col];
                }else{ 
                    out[row][col] = 0;
                }
            }
        }
    }

    writeImage(out, h, w);
    return 0;
}