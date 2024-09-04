#include <bits/stdc++.h>
using namespace std;
double power(double m, int n = 2)
{
    return pow(m, n);
}
int main()
{
    double m;
    cout << "Enter the base : ";
    cin>>m;
    int n;
    cout << "Enter the exponent : ";
    cin>>n;
    
    cout<<"Result : "<<power(m,n);
    return 0;
}
