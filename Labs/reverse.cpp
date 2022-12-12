//reverse.cpp 
#include <iostream>
#include <string>

using namespace std;


void reverse( string arr[], int size)
{
    int left=0;
    int right= size;
    
    while (left < right)
    {
        swap(arr[left], arr[right]);
        right ++;
        left --;
    }
}


int main()
{

    string greet[]= {"wow", "hello", "bye"};
    int s = sizeof(greet)/ sizeof(greet[0]);
    cout << s;
    
    for (int i =0; i <3; i++)
    {
        cout << arr[i] << endl;
    }

    reverse( greet, s );

    for (int i =0; i <3; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}