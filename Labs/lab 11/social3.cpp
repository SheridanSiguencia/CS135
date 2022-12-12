//social3.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: David Moncayo
Assignment: Lab 11C

Write a program social2.cpp, 
implementing the first version 
of the class Network (feel free 
to copy your class Profile and 
anything else from the previous program).
*/

#include <iostream>
#include <cctype>
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
    Profile()
    {
        username= "";
        displayname= "";
    }
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



//NETWORK
class Network 
{
private:
    static const int MAX_USERS = 20;// max number of user profiles

    int numUsers; 
    // number of registered users

    Profile profiles[MAX_USERS]; // user profiles array:
    // mapping integer ID -> Profile

    bool following[MAX_USERS][MAX_USERS];
    // Returns user ID (index in the 'profiles' array) by their username
    // (or -1 if username is not found)
    int findID (string usrn)
    {
        for (int i = 0; i < numUsers; i++)
        {   
            if (profiles[i].getUsername() == usrn)
                return i;  
        }

        return -1;
    }

public:
    // Constructor, makes an empty network (numUsers = 0)
    Network()
    {
        numUsers=0;
         
    }
    // Attempts to sign up a new user with specified username and displayname
    // return true if the operation was successful, otherwise return false
    bool addUser(string usrn, string dspn);

    bool follow(string usrn1, string usrn2); // new
    void printDot();
};


bool Network::addUser(string usrn, string dspn)
{   

    if (numUsers> MAX_USERS- 1)
        return false;

    if (findID(usrn) != -1)
        return false;   


    for (int j = 0; j < usrn.size(); j++)
    {
        if (!isalnum(usrn[j]))
            return false;       
    }   

    for (int k = 0; k < dspn.size(); k++)
    {
    
        if (!isalnum(dspn[k]))
            return false;
    }    
    
    profiles[numUsers]=Profile(usrn,dspn);

    numUsers++;

    return true;
}


bool Network::follow(string usrn1, string usrn2)
{   
    if (findID(usrn1)!= -1 && findID(usrn2) != -1 && (usrn1 != usrn2))
    {
        following[findID(usrn1)][findID(usrn2)] = true;

        return true;
    }
    return false;

}


void Network::printDot()
{

    cout << "digraph{ \n";
    for (int k = 0; k < numUsers; k++)   
        cout << "\t" << "\"@"  <<profiles[k].getUsername() << "\"" << endl;
    
    
    for (int i = 0; i < numUsers; i++)   
    {

        for(int j =0; j < numUsers; j++)
        {
            if(following[i][j] == true)
                cout << "\t" << "\"@"<< profiles[i].getUsername() <<"\""<< " -> " << "\"@"<<profiles[j].getUsername() << "\"" << endl;
        }
    }
    
    cout << "\n}";
}



int main() 
{
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) 
    {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario" + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }

    
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();
}