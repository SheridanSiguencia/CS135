//social.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: David Moncayo
Assignment: Lab 11A

In this task, write a program social.cpp, 
in which you have to implement the class 
Profile that can store the info about a 
user of the network.
*/

#include <iostream>
#include <string>
using namespace std;

class Profile {
private:
    string username;
    string displayname;
public:
    // Profile constructor for a user (initializing 
    // private variables username=usrn, displayname=dspn)
    Profile(string usrn, string dspn);

    // Default Profile constructor (username="", displayname="")
    Profile();

    // Return username
    string getUsername();
    // Return name in the format: "displayname (@username)"
    string getFullName();
    
    // Change display name
    void setDisplayName(string dspn);
};

Profile::Profile(string usrn, string dspn)
{
    username = usrn;
    displayname= dspn;
}

Profile::Profile()
{   
    username = "";
    displayname= "";
}

string Profile::getUsername()
{
    return username;
}
string Profile::getFullName()
{
    string name = displayname+ " (@"+ username +")";
    return name;
}

void Profile::setDisplayName(string dspn)
{
    displayname= dspn;

}


int main() {


    Profile p1[2];
    p1[0]= Profile("marco", "Marco");
    cout << p1[0].getUsername() << endl; 
    cout << p1[0].getFullName() << endl; 

    p1[0].setDisplayName("Marco Rossi");
    cout << p1[0].getUsername() << endl; 
    cout << p1[0].getFullName() << endl; 

    //p1[0]= Profile("marco", "Marco");
    cout << p1[1].getUsername() << endl; 
    cout << p1[1].getFullName() << endl; 

    Profile p2("tarma1", "Tarma Roving");
    cout << p2.getUsername() << endl; 
    cout << p2.getFullName() << endl; 

    cout << "\" Quote \"";
}
