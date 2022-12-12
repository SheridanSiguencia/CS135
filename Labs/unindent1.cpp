#include <iostream> 
using namespace std;

string removeLeadingSpaces(string line)
{
    int i;
    //read the line inputed
    for (i=0; i < line.size(); i++)
    {
        //if not a space break out of loop and return the rest of the line 
        if (!isspace(line[i]))
            break;
    }

    return line.substr(i);    
}

int main()
{
    string line;
    //reads lines of file one by one
    while(getline(cin, line))
    {
        string newline = removeLeadingSpaces(line);
        cout << newline << endl;
    }
    return 0;
}