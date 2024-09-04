//3.8: Write a program to print a table of values of the function Y = e-x For x varying from 0 to 10 in steps of 0.1. The table should appear as follows TABLE   FOR   Y =EXP[-X];    X     0.1      0.2       0.3      0.4      0.5      0.6     0.7      0.8      0.900 1.0 . . 9.0

// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    float x,y;
    cout<<"         TABLE FOR  Y=EXP(-X)             :\n\n";
    cout<<"x";
    for(float k=0;k<.7;k=k+0.1)
    cout<<setw(10)<<k;
    cout<<"\n";
    for(float k=0;k<10*.7;k=k+0.1)
    cout<<"-";
    cout<<"\n";
    for(float j=0;j<10;j++)
    {
        cout<<j<<setw(4);
        for(float i=0;i<.7;i=i+0.1)
        {
            x=i+j;
            y=exp(-x);
            cout.precision(6);
            cout.setf(ios::fixed,ios::floatfield);
            cout<<setw(10)<<y;             
}
cout<<"\n";
}
return 0; }
