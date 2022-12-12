//MemoryGame.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project 2
*/

#include "MemoryGame.hpp"
#include <cstdlib> //srand, rand
#include <ctime>
#include <iomanip> //setw
#include <iostream> //std
#include <vector>
using namespace std;

int* randomize(int numSlots); //function to randomize layout
void swap(int* arr, int i, int j);
void displaySeparateLine(int numSlots);

//TODO: implement by students
MemoryGame::MemoryGame() 
{
    //srand(time(NULL)); 
    //different layouts of numbers in different runnings.
    //time(NULL) is the current running time.
    //use the current running time to grow random sequence
    //Since running time differs,
    //the random sequence looks different
    //at different running time.
    srand(1); 

    numPairs = 3; //do not write int numPairs = 3;
    numSlots = 8; //3 pairs residing in 8 spaces,
                   //there are two empty spaces
    int *data;
    data = new int[numPairs];

    for (int i = 0; i < numPairs; i++)
        data[i] = rand() % 1000;

    int *arr = randomize(numSlots);

    values = new string[numSlots];

    for (int k = 0; k < numSlots; k++)
    {
        if (k < numPairs*2)
            values[arr[k]] = to_string(data[k/2]);
        else
            values[arr[k]] = "" ;
    }

    delete [] data;
    data = nullptr;

    delete [] arr;
    arr = nullptr;
}
//TODO: implement by students
MemoryGame::~MemoryGame()
{
    //When an object is no longer in need,
    //release dynamically allocated memory by 
    //data members of the current object.
    delete[] values;
    values = nullptr;

}

//TODO: implement by students
//randomize is not a member function,
//so there is no MemoryGame:: before function name randomize.
//Return an array of randomly allocated 0, 1, .., size-1
//In constructors, randomly assign the data in dataVector 
//to array values
int* randomize(int size)                                              
{
    int* arr;
    arr = new int[size];

    
    int r= rand()% size;

    // make normal array
    for (int i=0; i <size; i++)
        arr[i]= i;

    //swap with random position
    swap(arr, r, size-1);
    int pos = size -1;

    //continue going down swaping randomly
    for (int i= size-1; i > 0; i--)
    {
        pos -=1;
        r = rand () % i;
        swap(arr, r, pos);
    }

    return arr;
    //idea to randomize 0, 1, 2, 3, 4, 5,
    //generate a random int in [0, 6), say 3,
    //then move arr[3] to the end,
    //say, 0, 1, 2, 5, 4, 3
    //generate a random int in [0, 5), say 3 again,
    //then swap arr[3], which is 5 now, with arr[4], 
    //get 0, 1, 2, 4, 5, 3
    //generate a random int in [0, 4), say 2,
    //swap arr[2] with the current arr[3]
    //get 0, 1, 4, 2, 5, 3
    //continue to randomize arr[0..2].
    //afterwards, continue to randomize arr[0..1].

}

//TODO: implement by students
//int* arr means int array arr, which implies the address
//of the first element of array arr.
//swap arr[i] and arr[j] in array of ints arr.
void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i]= arr[j];
    arr[j]= temp;

}

//Display -----+ for numSlots times.
//Add an extra + when for the first block (when index i is 0).
//So suppose numSlots is 8, we get
//+-----+-----+-----+-----+-----+-----+-----+-----+
//followed by a new line.
void displaySeparateLine(int numSlots)
{
    
    for (int i = 0; i < numSlots; i++)
    {
        if (i == 0)
           cout << "+";
           
        cout << "-----+";
    }
    cout << endl;
}

//TODO: implement by students
//display the items in values array where bShown is true.
void MemoryGame::display(bool* bShown)
{
    cout<< " ";

//display label
    for(int i = 0; i < numSlots; i++)
    {
        cout << setw(3) << i ;
        cout<< setw(3) << " ";
    }
    cout << endl;

    displaySeparateLine(numSlots);

    cout << "|";
    for(int k = 0; k < numSlots; k++)
    {
        if(bShown[k])
            cout << setw(5) << values[k];
        else
            cout << setw(5) << "";

        cout << "|";
    }
    cout << endl;
    displaySeparateLine(numSlots); 
}

//TODO: implement by students
//rules for a round
//(1) pick a number, flip it
//(2) pick a second number, if the number is the same as
//    previous pick, display the second number,
//    otherwise, unflip the previous pick.
//(3) Finish until every pair are chosen correctly.
void MemoryGame::play()
{   
    bool* bShown;
    bShown = new bool[numSlots];

    for (int i =0; i < numSlots; i++)
        bShown[i]= false;

    int pairsFound = 0;
    int numFlips = 0;

    display(bShown);

    while (pairsFound < numPairs)
    {
        int num;
        int match;
        cout << "Pick a cell to flip: ";
        cin >> num;
        
        //the actually turn and asking 

        while(num < 0 || num > numSlots-1 || bShown[num]==true)
        {
            if(num < 0 || num > numSlots-1 )
                cout << "index needs be in range of [0, " << numSlots-1 << "]." << endl;
            
            else
                cout << "The cell indexed at " << num << " is shown." << endl;


            cout << "Re-enter an index: ";
            cin >> num;
        }

        //counting the number of flips
        numFlips++;

        if (numFlips % 2 != 0)
        {
            bShown[num] = true;
            match = num;
        }
        else
        {
            if ( (values[num] == values[match]) && (values[num] != ""))
            {
                bShown[num] = true;
                pairsFound++;
            }
            else 
            {
                bShown[match] = false;
            }
        }
        
        display(bShown);
    }
    cout << "Congratulations! Take "<< numFlips << " steps to find all matched pairs." << endl;
}       