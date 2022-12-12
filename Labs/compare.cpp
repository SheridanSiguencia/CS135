/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: David Moncayo
Assignment: Lab 3B
 
Write a program compare.cpp that asks the user to input two dates (the beginning and the end of the interval). The program should check each day in the interval and report which basin had higher elevation on that day by printing “East” or “West”, or print “Equal” if both basins are at the same level.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

int main() {
  
  string date, start, end;
  double eastSt, eastEl, westSt, westEl;
  
  cout << "Enter starting date: " << start;
  cin >> start;
  cout << "Enter ending date:  " << end;
  cin >> end;
  
  ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()) {
    cerr << "File cannot be opened for reading." <<     endl;
    exit(1); // exit if failed to open the file
  }
  junk:

  string junk;        // new string variable
  getline(fin, junk); //read one line from the file
  
  while(fin >> date >> eastSt >> eastEl >> westSt >>  westEl) { 
    // this loop reads the file line-by-line
    // extracting 5 values on each iteration 
    
    fin.ignore(INT_MAX, '\n'); //skips to the end of line,ignorring the remaining columns 
    
  //to print the min and mas of the Eastbasin storage:
    if (start <= date and date <= end) {
      if (eastEl > westEl){
        cout << date << " East \n";
      } else if (eastEl < westEl){
        cout << date << " West \n";
      } else {
        cout << date << "Equal \n";
      }
    }
  }
  
  fin.close();
  return 0;
}