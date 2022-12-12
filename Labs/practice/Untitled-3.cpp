//recursion practice


#include <iostream>
using namespace std;

void recursion(int max, int min)
{
    
    if(min <= max)
    {
        cout << min <<" ";
        return recursion(max,min+2);
    } 
}


int main()
{
    int a,b;
    
    cout << "Enter a max: ";
    cin >> a;

    cout << "Enter a min: ";
    cin >> b;
    
    recursion(a,b);

     
    return 0;
}