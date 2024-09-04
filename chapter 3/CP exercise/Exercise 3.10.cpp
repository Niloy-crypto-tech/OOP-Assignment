#include <bits/stdc++.h>
using namespace std;

int main() {
    int unit;
    float charge,additional;
    char name[40];
    while(1)
    {
        input:
        cout<<" Enter consumer name & unit consumed :";
        cin>>name>>unit;
        if(unit<=100)
        {
            charge=50+(60*unit)/100;
            }
            else if(unit<=300 && unit>100)
            {
                charge=50+(80*unit)/100;
                }
                else if(unit>300)
                {
                    charge=50+(90*unit)/float(100);
                    additional=(charge*15)/100;
                    charge=charge+additional;
                    }
                cout<<setw(15)<<"Name"<<setw(20)<<"Charge"<<endl;
                cout<<setw(15)<<name<<setw(20)<<charge<<endl;
            cout<<" Press o for exit / press 1 to input again :";
            int test;
            cin>>test;
            if(test==1)
            goto input;
            else if(test==0)
            break;
            }
            
return 0; }
