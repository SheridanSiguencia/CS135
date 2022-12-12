//E6_20.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW E6.20

Write a function

vector<int> merge_sorted(vector<int> a, vector<int> b)
that merges two sorted vectors, producing a new sorted vector. 
Keep an index into each vector, indicating how much of it has 
been processed already. Each time, append the smallest unprocessed 
element from either vector, then advance the index. 

For example, if a is
1 4 9 16

and b is
4 7 9 9 11

then merge_sorted returns the vector
1 4 4 7 9 9 9 11 16
*/

#include <iostream> 
#include <vector>
using namespace std;


vector<int> merge_sorted(vector<int> a, vector<int> b);

int main()
{

    vector<int> a = {1, 4, 9, 16};
    vector<int> b = {4, 7, 9, 9, 11};

    
    vector<int> c= merge_sorted(a,b);

    for (int i= 0; i < a.size(); i++)
        cout << a[i] << " ";

    cout << "size of a " << a.size() << endl << "Size of c is " << c.size() << endl;


    for (int i= 0; i < c.size(); i++)
        cout << c[i] << " ";


    

    

}

vector<int> merge_sorted(vector<int> a, vector<int> b)
{
    vector<int> temp;
    int k = 0;
    int max = a.size() + b.size();
    int i = 0;
    int j = 0;

    while(k < max)
    {
        if (i == a.size())
            a.push_back(9999); 
        
        if (j == b.size())
            b.push_back(9998); 

        
        
        if (a[i]<=b[j])
        {
            temp.push_back(a[i]);
            i++;
        }
        else if (a[i]> b[j])
        {
            temp.push_back(b[j]);
            j++;
        }
    
        k++;
    }
    
    return temp;
}
