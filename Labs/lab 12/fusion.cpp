//fusion.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: David Moncayo
Assignment: Lab 12C


Make a program called fusion.cpp that implements the function 
void gogeta(vector<int> &goku, vector<int> &vegeta) 
that appends elements of the second vector into the 
first and empties the second vector. 
*/

#include <iostream>
#include <vector>

using namespace std;


void gogeta(vector<int> &goku, vector<int> &vegeta); 

int main()
{
    vector<int> v1{1,2,3};
    vector<int> v2{4,5};

    for(int i= 0; i < v1.size(); i++)
        cout << "element " << i<< "v1:"<< v1[i] << " v2: " << v2[i] << ".\n";

    gogeta(v1,v2);

    for(int i= 0; i < v1.size(); i++)
        cout << "element "<< i << " v1 " << v1[i] << endl;
    
    for (int i= 0; i < v2.size(); i++)
        cout << " v2: " << v2[i] << ".\n";

    return 0;
}

void gogeta(vector<int> &goku, vector<int> &vegeta) 
{
    for (int i =0; i <vegeta.size(); i++)
        goku.push_back(vegeta[i]);
    
    
    
    vegeta.clear();

}