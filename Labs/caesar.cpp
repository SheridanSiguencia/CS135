//caesar.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: David Moncayo
Assignment: Lab 6B


Write a program caesar.cpp with 
functions implementing Caesar cipher encryption:
*/

#include <iostream>
#include <cctype>
using namespace std;

// A helper function to shift one character by rshift
char shiftChar(char c, int rshift);


// Caesar cipher encryption
string encryptCaesar(string plaintext, int rshift);

int main ()
{
    string str;
    int num;

    cout << "Enter plaintext: ";
    getline (cin, str);

    cout << "Enter shift: ";
    cin >> num;

    string code = encryptCaesar( str, num);

    cout << "Ciphertext: " << code;

    return 0;
}


// A helper function to shift one character by rshift
char shiftChar(char c, int rshift)
{
    //capitals
    if (65<= int(c) && int(c)<=90)
    {   
        c += rshift;

        if ( c > 90)
        {
            c -=26;
            return c;
        }

        return c; 

    } 
    //lower case
    else if (97 <= int(c) && int(c) <= 122)
    {   //c might get too hight in the future for the ascii
        // table to translate 
        int a = int(c) + rshift;

        if (a > 122)
        {
            
            
            a -= 26;

            c= a;
            return c;
        }

        c= a;
        return c; 

    } 

    //if not in the alphabet do nothing to symbol /space
    return c;
}

// Caesar cipher encryption
string encryptCaesar(string plaintext, int rshift)
{
    char ch;
    
    //string coded;

    for (int i=0; i < plaintext.length(); i++)
    {
        ch= plaintext[i];

        plaintext[i] = shiftChar(ch , rshift);

    }

    return plaintext;
    
}