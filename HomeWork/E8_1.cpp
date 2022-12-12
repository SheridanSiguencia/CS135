// E8_1.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: Tong Yi
Assignment: HW E8.1

Write a program that carries out the following tasks:

Open a file with the name hello.txt.
Store the message “Hello, World!” in the file.
Close the file.
Open the same file again.
Read the message into a string variable and print it.

*/

#include <iostream>
#include <fstream>
using namespace std;

main ()
{
    ofstream myFile;
    myFile.open("hello.txt");
    myFile << "Hello, World!";
    myFile.close();

    //make storing message
    string message;

    ifstream read;
    read.open("hello.txt");

    while (read >> message)
    {
        cout << message << " ";
    }
}