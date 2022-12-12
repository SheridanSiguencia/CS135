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



Board::Board() : Board(3,3) {

    

}







Board::Board(int m) : Board(m, m){ 



}



Board::Board(int m, int n){



    if (m >= 1 && n >= 1){

        numRows = m; 

        numCols = n; 

    }



    else{

        numRows = 3; 

        numCols = 3;  

    }



    panel = new int*[numRows];

    for(int i = 0; i < numRows; i++){

        panel[i] = new int [numCols]; 

        for (int j = 0; j < numCols; j++){

            panel[i][j]; 

        }

    }



    max = 0; 

    target = 32; 



}


Board::~Board(){ // destructor for panel array



    for (int i = 0; i < numRows; i++){

        delete[] panel[i]; 

        panel[i] = nullptr; 

    }

    delete[] panel; 

    panel = nullptr; 



}



void printSeperateLine(int x)
{
    for(int i = 0; i < x; i++){ 

        cout << "+----"; 

    }

    cout << "+" << endl; 
}



void Board::print() const{ // print method



    printSeperateLine(numCols); 

    for(int i = 0; i < numRows; i++){

        for(int j = 0; j < numCols; j++){

            if (panel[i][j] != 0)
                cout << "|" << setw(4); //<< panel[i][j]; 
            else
                cout << "|" << setw(4) << " "; 


        }

        cout << "|" << endl; 

        printSeperateLine(numCols); 

    }

    

}


/*
bool Board::noAdjacentSameValue() const{

    for(int i = 0; i < numRows; i++){

        for(int j = 0; j < numCols - 1; j++){

           if(panel[i][j] == panel[i][j + 1]){

               return false; 

           }

        }

    }

   for(int i = 0; i < numCols; i++){

       for(int j = 0; j < numRows - 1; j++){

           if(panel[j][i] == panel[j + 1][i]){

               return false; 

           }

       }

   }

   for(int i = 0; i < numRows; i++){

       for(int j = 0; j < numCols; j++){

           if(panel[i][j] == 0){

               return false; 

           }

       }

   }

   

   return true; 

}



void Board::selectRandomCell(int& row, int& col){

    struct emptyCell{

        int row; 

        int col; 

        

    }; 

    emptyCell x; 

    int tally = 0; 

    vector <emptyCell> empty; 

    for(int i = 0; i < numRows; i++){

        for(int j = 0; j < numCols; j++){

            if(panel[i][j] == 0){

                x.row = i; 

                x.col = j; 

                empty.push_back(x); 

                tally = tally + 1; 

            }

        }

    }

    if(tally == 0 && noAdjacentSameValue() && max < target){ 

        cout << "Game over. Try again."<<endl; 

        exit(0);

    }



    if(noAdjacentSameValue() && tally > 0){ //

        cout << "Game over. Try again."<<endl; 

         exit(0);

    }

    if(tally > 0 ){

        int random; 

        random = rand() % empty.size(); 

        panel[empty[random].row][empty[random].col] = 1; 

        print(); 

    }

    if(noAdjacentSameValue() && max < target){ 

        cout << "Game over. Try again." <<endl; 

        exit(0); 

    }

}
*/