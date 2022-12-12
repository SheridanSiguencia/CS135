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
    
    string getDisplayname();


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

string Profile::getDisplayname()
{
    return displayname;
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

struct Post{
  string username;
  string message;

};

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

// new private data used in posts lab d
    static const int MAX_POSTS = 100;
    int numPosts;             // number of posts
    Post posts[MAX_POSTS]; 

    /*
    struct Post{
        string username;
        string message;
    };
        */
public:
    // Constructor, makes an empty network (numUsers = 0)
    Network()
    {
        numUsers=0;
        numPosts =0;
         
    }
    
    // Attempts to sign up a new user with specified username and displayname
    // return true if the operation was successful, otherwise return false
    bool addUser(string usrn, string dspn);

    bool follow(string usrn1, string usrn2); // new
    void printDot();

    //adds a new post
    bool writePost(string usrn, string msg);

    // Print user's "timeline"
    bool printTimeline(string usrn);

    int numberPosts();

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

//adds message
bool Network::writePost(string usrn, string msg)
{   
   
    if (numPosts> MAX_POSTS- 1)
        return false;
    posts[numPosts].username =usrn;
    posts[numPosts].message = msg;
    numPosts++;

    return true;
}

    // Print user's "timeline"
bool Network::printTimeline(string usrn)
{   
    string friends;

    for (int i = 0; i < numUsers; i++)   
    {
        if(following[findID(usrn)][i] == true)
            friends= profiles[i].getUsername();
            break;

    }
    
    for (int i =0; i < numPosts; i++)
    {
        /*
        cout << profiles[findID(usrn)].getDisplayname() << " (@" << profiles[findID(usrn)].getUsername() << posts[i].message;
        cout << endl;
        */
        if (posts[i].username == usrn )
        {
            
        //ex Displayname (@username): message
        
            cout << profiles[findID(usrn)].getDisplayname() << " (@" << profiles[findID(usrn)].getUsername() << ") :" << posts[i].message << endl;
        }

        if (posts[i].username == friends )
        {
            
        //ex Displayname (@username): message
        
            cout << profiles[findID(friends)].getDisplayname() << " (@" << profiles[findID(friends)].getUsername() << ") :" << posts[i].message << endl;
        }
        
        
    }

    return true;
}

int Network::numberPosts()
{
    return numPosts;
}

int main() 
{
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");
   
    nw.follow("mario", "luigi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");

    // write some posts
    nw.writePost("mario", "It's a-me, Mario!");
    nw.writePost("luigi", "Hey hey!");
    nw.writePost("mario", "Hi Luigi!");
    nw.writePost("yoshi", "Test 1");
    nw.writePost("yoshi", "Test 2");
    nw.writePost("luigi", "I just hope this crazy plan of yours works!");
    nw.writePost("mario", "My crazy plans always work!");
    nw.writePost("yoshi", "Test 3");
    nw.writePost("yoshi", "Test 4");
    nw.writePost("yoshi", "Test 5");

    cout << endl;
    cout << "======= Mario's timeline =======" << endl;
    nw.printTimeline("mario");
    cout << endl;

    cout << "======= Yoshi's timeline =======" << endl;
    nw.printTimeline("yoshi");
    cout << endl;

    nw.printDot();
    cout << nw.numberPosts();
    
}