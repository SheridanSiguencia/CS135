
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project 3A

Define constructor, destructor, 
and method pront for Board.cpp
*/

#include "Board.hpp"
#include <cstdlib> //srand, rand
#include <ctime>
#include <iomanip> //setw
#include <iostream> //std
#include <vector>

using namespace std;

Board::Board()
{
    numRows = 3;
    numCols = 3;

    max = 0;
    target = 32;

    panel= new int * [numRows];

    for (int row=0; row < numCols; row++)
        panel[row] = new int[numCols];
}

/*(1.2)	For Board(int m), set numRows to be m and 
numCols to be m if m is >= 1, otherwise, set numRows 
and numCols to be 3. Set panel to be a two-dimensional 
array with numRows rows and numCols columns, 
set max to be 0 and target to be 32.
*/

Board::Board(int m)
{   

    if (m>= 1)
    {
        numRows = m;
        numCols = m;
    } else {
        numRows = 3;
        numCols = 3;
    }
    

    max = 0;
    target = 32;

    panel= new int * [numRows];

    for (int row=0; row <numCols; row++)
        panel[row] = new int[numCols];
}



Board::Board(int m, int n)
{
    max = 0; 
    target = 32; 

    if (m >= 1 && n >= 1)
    {
        numRows = m; 
        numCols = n; 
    }else{
        numRows = 3; 
        numCols = 3;  
    }

    panel = new int*[numRows];

    for(int i = 0; i < numRows; i++)
    {
        panel[i] = new int [numCols]; 
        for (int j = 0; j < numCols; j++)
            panel[i][j]; 
    }

    
}


Board::~Board(){ // destructor for panel array



    for (int i = 0; i < numRows; i++)
    {

        delete[] panel[i]; 

        panel[i] = nullptr; 

    }

    delete[] panel; 
    panel = nullptr; 
}


void Board::print() const
{ 
    for(int i = 0; i < numCols; i++)
        cout << "+----"; 

    cout << "+" << endl; 

    for(int i = 0; i < numRows; i++)
    {

        for(int j = 0; j < numCols; j++)
        {

            if (panel[i][j] != 0 && panel[i][j])
                cout << "|" << setw(4) <<panel[i][j];  
            else
                cout << "|" << setw(4) << " "; 

        }

        cout << "|" << endl; 

        for(int i = 0; i < numCols; i++)
            cout << "+----"; 

        cout << "+" << endl;  
    } 
}

bool Board::noAdjacentSameValue() const
{
    //checks horizontally
    for(int i = 0; i < numRows; i++)
    {
        for(int j = 0; j < numCols - 1; j++)
        {
            if(panel[i][j] == panel[i][j + 1])
                return false; 

        }
    }

    //checks vertically for (int j = 0; j < numCols; j++)
    //for (int i = 0; i < numRows – 1; i++)

    for(int j = 0; j < numCols; j++)
    {
        for(int i = 0; i < numRows - 1; i++)
        {
            if(panel[i][j] == panel[i + 1][j])
                return false; 
       }
    }

    //checks if everything is empty 
    for(int r = 0; r < numRows; r++)
    {
        for(int c = 0; c < numCols; c++)
        {
            if(panel[r][c] == 0)
                return false; 
        }
    }

    if (max < target)
        return true;
    return true;
}


void Board::selectRandomCell(int& row, int& col)
{
    struct emptyCell
    {
        int r; 
        int c;
    }; 

    emptyCell x; 

    int count = 0; 

    vector <emptyCell> empty; 

    for(int i = 0; i < numRows; i++)
    {
        for(int j = 0; j < numCols; j++)
        {
            if(panel[i][j] == 0)
            {
                x.r = i; 
                x.c = j; 

                empty.push_back(x); 
                count += 1; 
            }
        }
    }
    /*
    if(count == 0 && noAdjacentSameValue())
    { 
        cout << "Game over. Try again."<<endl; 
        exit(0);
    }
    
    if(noAdjacentSameValue())
    { 
        cout << "Game over. Try again."<<endl; 
        exit(0);
    }
    */
    if(count > 0)
    {
        int random; 
        random = rand() % empty.size(); 
        panel[empty[random].r][empty[random].c] = 1; 
        print(); 
    }

    if(noAdjacentSameValue())
    { 
        cout << "Game over. Try again." <<endl; 
        exit(0); 
    }

}


void Board::pressUp(){

    for(int col = 0; col < numCols; col++)
    {
        vector <int> notZero; 
        for (int row = 0; row < numRows; row++)
        {
            if(panel[row][col] != 0)
                notZero.push_back(panel[row][col]); 
             

        }

       int current = 0; 
       int row = 0; 

       while(current < notZero.size())
       {
            if(current + 1 < notZero.size() && notZero[current] == notZero[current + 1])
            {
                panel[row][col] = notZero[current]*2; 
                current += 2; 

                if((notZero[current]*2)> max)
                    max = notZero[current]*2; 

            }else{

                panel[row][col] = notZero[current]; 
                current += 1; 
            }
            row += 1;
        }

        for(int r = row; r < numRows; r++)
            panel[r][col] = 0; 

    }

    int a;
    int b; 

    selectRandomCell(a, b); 

}

void Board::pressDown(){

    for(int col = 0; col < numCols; col++)
    {
        vector <int> notZero; 
        int current = 0;

        for (int row = numRows - 1; row >= 0; row--)
        {

            if(panel[row][col] != 0)
                notZero.push_back(panel[row][col]); 

        }

        int row = numRows - 1; 

        while(current < notZero.size())
        {
            if(notZero[current] == notZero[current + 1] && current + 1 < notZero.size())
            {

                panel[row][col] = notZero[current]*2; 

                current += 2; 

                if((notZero[current]*2)> max)
                    max = notZero[current]*2; 
            }else{

                panel[row][col] = notZero[current]; 
                current += 1; 
            }
            row -= 1;
        }

        for(int r = row; r >= 0; r--)
            panel[r][col] = 0; 

    }

    int a; 
    int b; 

    selectRandomCell(a, b); 

}


void Board::pressLeft()
{
    for(int row = 0; row < numRows; row++)
    {

        vector <int> nonZeros; 

        for (int col = 0; col < numCols; col++)
        {
            if(panel[row][col] != 0)
            {
                nonZeros.push_back(panel[row][col]); 
            }    
        }

        int current = 0; 
        int col = 0; 

        while(current < nonZeros.size())
        {

            if(current + 1 < nonZeros.size() && nonZeros[current] == nonZeros[current + 1])
            {
                panel[row][col] = nonZeros[current]*2; 
                current += 2; 

                if((nonZeros[current]*2)> max)
                    max = nonZeros[current]*2; 

            }else{
                panel[row][col] = nonZeros[current]; 
                current += 1; 
            }
            col += 1;
        }

        for(int c = col; c < numCols; c++){

            panel[row][c] = 0; 
        }
    }

    int a; 
    int b; 

    selectRandomCell(a, b); 

}

void Board::pressRight(){

    for(int row = 0; row < numRows; row++)
    {
        vector <int> notZero; 

        for (int col = numCols - 1; col >= 0; col--)
        {
            if(panel[row][col] != 0)
                notZero.push_back(panel[row][col]); 
        }

        int current = 0; 

        int col = numCols - 1; 

        while(current < notZero.size())
        {

            if(current + 1 < notZero.size() && notZero[current] == notZero[current + 1])
            {
                panel[row][col] = notZero[current] * 2; 
                current += 2; 

                if((notZero[current]*2)> max)
                    max = notZero[current]*2; 

            }else{

                panel[row][col] = notZero[current]; 
                current += 1; 
            }
            
            col-= 1;
        }

        for(int c = col; c >= 0; c--)
            panel[row][c] = 0; 

    }

    int a;
    int b; 

    selectRandomCell(a, b); 

}

void Board::setGoal(int goal)
{
    target= goal;
}
void Board::start()
{
    int round = 1;
    
    //TODO: call selectRandomCell twice to generate two values
    int a,b,c,d;
    selectRandomCell(a, b); 
    selectRandomCell(c, d); 

    char ch;
    while (true)
    {   
        
        if (max > target) //in case goal is not a power of 2,
        {
            cout << "Congratulation!" << endl;
            break;
        }
        if (round == 46)
        {
            cout << "Congratulation!" <<endl;
            break;
        }

    //https://stackoverflow.com/questions/10463201/getch-and-arrowcodes
    //cannot replace getchar by getch
    //When encountering letter S, even if the
    //project does not finish running yet,
    //can leave while (true) loop.
    //Add this line to stop time out exception.
        ch = getchar();
        if (ch == 'S')
            break;
        
        //if (ch == '\[')
        if (ch == '\033') 
        { // if the first value is esc
            getchar(); // skip the [
            
            switch(getchar()) 
            { // the real value
                case 'A':
    // code for arrow up
                    cout << "Round " << setw(4) << round << ": ";
                    cout << "Press UP. " << "Goal: " << target << endl;
                    pressUp();
                    round++;
                    break;
                case 'B':
                    cout << "Round " << setw(4) << round << ": ";
                    cout << "Press DOWN. " << "Goal: " << target << endl;
                    pressDown();
                    round++;
                    break;
                case 'C':
                    cout << "Round " << setw(4) << round << ": ";
                    cout << "Press RIGHT. " << "Goal: " << target << endl;
                    pressRight();
                    round++;
                    break;
                case 'D':
                    cout << "Round " << setw(4) << round << ": ";
                    cout << "Press LEFT. " << "Goal: " << target << endl;
                    pressLeft();
                    round++;
                    break;
    //TODO: finish the rest of code.
            }
            
        }

    }
    
}