#include<iostream>
using namespace std;
int m=10;
int main(){
    int m=20;
    {
        int k=m;
        int m=30;
        cout<<"Inner Block"<<endl;
        cout<<"k ="<<k<<endl;
        cout<<"m ="<<m<<endl;
        cout<<"::m = "<<::m<<endl;
    }
    cout<<endl<<"Outer Block"<<endl;
    cout<< "m = "<<m<<endl;
    cout<<"::m = "<< ::m<<endl;
    return 0;
}
