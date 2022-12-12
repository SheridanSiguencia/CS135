//E5.6
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: Tong Yi
Assignment: E5.6

that returns a string containing the middle 
character in str if the length of str is odd, 
or the two middle characters if the length is even. 
For example, middle("middle") returns "dd".


*/


#include <iostream>
using namespace std;

string middle(string str){
    int calc = (str.length())/2;
    string mid;
    if ( (calc %2) != 0) {
        int add= calc - 1;
        string one,two;
        one = str[calc];
        two= str[add];
        mid= one + two;
        
       
    } else {
        mid= str[calc];
    } 
    
    return mid;
    
}

int main() 
{
    string str;
    cout << "Enter string: ";
    cin >> str;
    string result = middle(str);

    cout << "Middle is " << result;
    
   
    return 0;



}