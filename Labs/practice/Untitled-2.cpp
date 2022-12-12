/*
Use for loop to print 7 elements of the following sequence 1/1,2/4,... ,n/n^2.

*/


#include <iostream>
#include <cmath>
using namespace std;

main()
{
    float num=0;
    //M_PI
    for(int i=6; i<=32; i++)
    {
        num += sqrt(M_PI)/ (i+5);
        cout << num << endl;
    }
    cout << "Final: " << num << endl;

}