//decryption.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: David Moncayo
Assignment: Lab 6C


Implement two decryption functions corresponding
to the above ciphers. When decrypting ciphertext,
ensure that the produced decrypted string is equal
to the original plaintext:

decryptCaesar(ciphertext, rshift) == plaintext
decryptVigenere(ciphertext, keyword) == plaintext

Write a program decryption.cpp that uses the above
functions to demonstrate encryption and decryption
for both ciphers.

It should first ask the user to input plaintext,
then ask for a right shift for the Caesar cipher
and report the ciphertext and its subsequent
decryption. After that, it should do the same
for the Vigenere cipher.
*/

#include <iostream>
#include <cctype>
using namespace std;

// A helper function to shift one character by code word
char shiftChar(char c, int rshift);


// Caesar cipher encryption
string encryptCaesar(string plaintext, int rshift);

//Vigenere cipher encryption
string encryptVigenere(string plaintext, string kword);

string decryptCaesar(string ciphertext, int rshift);

string decryptVigenere(string ciphertext, string kword);


int main ()
{   
    string str;
    int num;

    cout << "Enter plaintext: ";
    getline (cin, str);

    //caesar cipher
    
    cout << endl << "= Caesar = \n";

    cout << "Enter shift: ";
    cin >> num;

    string code = encryptCaesar( str, num);
    cout << "Ciphertext: " << code << endl;

    string decode = decryptCaesar(code, num);
    cout << "Decrypted: " << decode << endl;

    //vigenere cipher
    cout << endl << "= Vigenere =" << endl;

    string key;
    cout << "Enter keyword: ";
    cin >> key;

    code = encryptVigenere(str, key);

    cout << "Ciphertext: " << code << endl;

    decode = decryptVigenere(code, key);
    cout << "Decrypted: " << decode;

    return 0;
}


// A helper function to shift one character by shift
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
        } else if ( c < 65) {
            c +=26;
            return c;
        }

        //if normal and no need to loop around
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
        } else if (a < 97)
        {
            a += 26;

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



string decryptCaesar(string ciphertext, int rshift)

{
    char ch;
    
    int lshift = (-1) * rshift;

    //string coded;

    for (int i=0; i < ciphertext.length(); i++)
    {
        ch= ciphertext[i];

        ciphertext[i] = shiftChar(ch , lshift);

    }

    return ciphertext;
}

string decryptVigenere(string ciphertext, string kword)
{
    char ch;
    char kchar; 
    int n =0 ;


    for (int i=0; i < ciphertext.length(); i++)
    {   
        if (n > kword.size()- 1)
        {
            n = 0;
        }
        
        ch= ciphertext[i];        
        kchar = kword[n];

        int kshift = (int(kchar) - 97);

        kshift *= -1;

        //if not a letter then dont shift at all 
        if (isalpha(ch)==0)
        {
            ciphertext[i] = shiftChar(ch , 0);
        } else {

            //shift if by letter and adds to n to keep the key going
            ciphertext[i] = shiftChar(ch , kshift);
            n++;
        }

    }
    return ciphertext;
}
