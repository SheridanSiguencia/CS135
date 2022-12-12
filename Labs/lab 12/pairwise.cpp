//pairwise.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: David Moncayo
Assignment: Lab 12D

Write a program called pairwise.cpp that implements the function 
vector<int> sumPairWise(const vector<int> &v1, const vector<int> &v2) 
that returns a vector of integers whose elements are the pairwise sum of 
the elements from the two vectors passed as arguments. If a vector has a 
smaller size than the other, consider extra entries from the shorter vectors as 0
*/


#include <iostream>
#include <vector>

using namespace std;

vector<int> sumPairWise(vector<int> &v1, vector<int> &v2); 


int main()
{
    vector<int> v2{1,2,3};
    vector<int> v1;

    vector<int>v3 = sumPairWise(v1, v2); // returns [5, 7, 3]

    cout << "returns ["<< v3[0];
    for (int i = 1; i< v3.size(); i++)
        cout <<", " << v3[i];

    cout << "]";

    return 0;
}

vector<int> sumPairWise(vector<int> &v1, vector<int> &v2) 
{

    vector<int> v3;
    //makes size of the v2 equal v1 by adding 0
    while (v1.size() > v2.size())
        v2.push_back(0);

    //or viceversa
    while (v2.size() > v1.size())
        v1.push_back(0);
    

    for (int i=0 ; i < v2.size(); i++)
    {

        v3.push_back(v1[i]+ v2[i]);
    }

    /*
    for (int j= v2.size(); j < v1.size(); j++)
        v3.push_back(v1[j]);
    */

    
    return v3;
}
