// 2.3: Write a program to input an integer from the keyboard and display on the screen “WELL DONE” that many times.

#include<iostream>
using namespace std;
int main() {     
    int n;     
    string str="WELL DONE"; 
     cout<<" Enter an integer value: "<<endl;  
     cin>>n;     
     for(int i=0;i<n;i++)     
     {         cout<<str<<endl;    
     }    
     return 0;
    
}
