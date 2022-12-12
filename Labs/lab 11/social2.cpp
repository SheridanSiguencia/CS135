//social2.cpp
/*
Author: Sheridan Siguencia
Course: CSCI-135
Instructor: David Moncayo
Assignment: Lab 11B

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




class Network 
{
private:
    static const int MAX_USERS = 20;// max number of user profiles
    int numUsers;         // number of registered users
    Profile profiles[MAX_USERS]; // user profiles array:
    // mapping integer ID -> Profile

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

    
};



bool Network::addUser(string usrn, string dspn)
{   

    if (numUsers> MAX_USERS- 1)
        return false;
    /*
    for (int i = 0; i < numUsers; i++)
    {   
        if (profiles[i].getUsername() == usrn)
            return false;
            
    }    
    */
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


int main() 
{
    Network nw;
    cout <<nw.addUser("mario", "Mario") << endl;     // true (1)
    cout <<nw.addUser("luigi", "Luigi") << endl;     // true (1)

    cout <<nw.addUser("mario", "Mario2") << endl;    // false (0)
    cout <<nw.addUser("mario 2", "Mario2") << endl;  // false (0)
    cout << nw.addUser("mario-2", "Mario2") << endl;  // false (0)

    for(int i = 2; i < 6; i++) 
    {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario" + to_string(i);
        cout<< nw.addUser(usrn, dspn) << "yo \n";
        
    }
    cout <<nw.addUser("yoshi", "Yoshi") << endl;     // false (0)

    
}