#include <iostream>
#include <cctype>
using namespace std;

int main ()
{

    string str= "F***2Off_bro";
    string n= "";


    for(int i = 0; i < str.size(); i++)
    {
        //if str char is a letter or a number then add to string if not dont add it
        if (isalnum(str[i]))
            n += str[i];
    }    

    cout << n;
}