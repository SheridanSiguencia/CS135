//memoryGame.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project 2
*/

#include <iostream>
#include <cstdlib>
using namespace std;

class MemoryGame
{
    //private data members, private means that
    //only methods in this class, not other class,
    //can access or modify these data members.
    int
    numPairs;
    //numPairs of identical twin items
    int numSlots;
    //size of array value, besides identical twins,
    //may contain empty string to make the problem more challenging
    string *values;
    //a string to represent the layout of data,
    //mixed with possible empty strings.
    //Use array to access each element in const time

public:
    MemoryGame();//default constructor, with 3 pairs of numbers
    //randomly located in 8 blocks (two blocks are empty).
    ~MemoryGame(); //destructor
    void play();    //play the game
    void display(bool * bShown);
    //display array values.
    //if bShown[i], where i is index, is true,
    //them values[i] is displayed, otherwise, values[i] is not displayed.
};

//functions swap and randomize
void swap(int &a, int &b);
void randomize(int *ar);

int main ()
{
    int data[] = {11,22,33};
    int arr[8]= {data[0], data[0], data[1], data[1], data[2], data[2]};
    //cout << arr[0] << " and " << arr[2] << " and " << arr[4] << " and " << arr[6];
    int array[8] = {0,1,2,3,4,5,6,7};
    
    randomize(arr);

    for (int i = 0; i< 8; i++)
    {   
        
        cout << "array slot "<< i << " is "<< arr[i] << endl;
        
    }
    return 0;
}

void swap( int &a, int &b)
{
    int c = a;
    a =b;
    b= c;


}

void randomize(int *ar)
{
    srand(1);
    for(int i=0; i<8; i++)
    {
        swap( ar[rand()%8], ar[rand()%8] );
    }
}
