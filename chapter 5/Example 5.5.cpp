#include<bits/stdc++.h>
using namespace std;
class employee{
    char name[30];
    float age;

    public:
        void getdata();
        void putdata();
};
void employee :: getdata()
{
    cout<<"enter name : ";
    cin>>name;

    cout<<"enter age : ";
    cin>>age;
}
void employee :: putdata()
{
    cout<<"name : "<<name<<endl;
    cout<<"age : "<<age<<endl;
}

const int n = 3;

int main()
{
    employee manager[n];
    for(int i=0; i<n; i++)
    {
        cout<<"details of manager"<<i+1<<endl;
        manager[i].getdata();
    }
    cout<<endl;

    for(int i=0; i<n; i++)
    {
        manager[i].putdata();
    }
    
    return 0;
}
