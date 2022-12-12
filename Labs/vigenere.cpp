//vigenere.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: David Moncayo
Assignment: Lab 6C


Write a program vigenere.cpp. 
It should contain a function 
encryptVigenere implementing this cipher:
string encryptVigenere(string plaintext, string keyword);
You may assume that the keyword contains only
 lowercase alphabetic characters a - z.

The main should implement a testing 
interface similar to the one in Task B, 
the user enters the plaintext and the keyword, 
and the program reports the ciphertext.
*/

#include <iostream>
#include <cctype>
using namespace std;

// A helper function to shift one character by code word
char shiftChar(char c, int rshift);


// Caesar cipher encryption
string encryptVigenere(string plaintext, string kword);

int main ()
{
    string str;
    string key;

    cout << "Enter plaintext: ";
    getline (cin, str);

    cout << "Enter keyword: ";
    cin >> key;

    string code = encryptVigenere(str, key);

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

// Vigenere cipher encryption
string encryptVigenere(string plaintext, string kword)
{
    char ch;
    char kchar; 
    int n =0 ;


    for (int i=0; i < plaintext.length(); i++)
    {   
        if (n > kword.size()- 1)
        {
            n = 0;
        }
        
        ch= plaintext[i];        
        kchar = kword[n];

        int kshift = (int(kchar) - 97);

        //if not a letter then dont shift at all 
        if (isalpha(ch)==0)
        {
            plaintext[i] = shiftChar(ch , 0);
        } else {

            //shift if by letter and adds to n to keep the key going
            plaintext[i] = shiftChar(ch , kshift);
            n++;
        }

    }
    return plaintext;
}