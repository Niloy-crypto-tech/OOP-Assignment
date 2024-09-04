#include <bits/stdc++.h>
using namespace std;
int add(int x, int y)
{
    int z = x + y;
    return z;
}
double add(double x,double y)
{
    double z = x+y;
    return z;
}
double add(int x, double y)
{
    double z = x+y;
    return z;
}
int main()
{
    cout<<add(3,7)<<endl;   //calls add(int x, int y)
    cout<<add(5.9,9.2)<<endl;   //calls double add(double x,double y)
    cout<<add(6,7.5)<<endl;     //calls add(int x, double y)


    return 0;
}
