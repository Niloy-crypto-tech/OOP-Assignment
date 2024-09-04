#include<bits/stdc++.h>
using namespace std;
class integer{
    int m,n;

    public:
        integer(int x,int y);       //constructor decleared
        void display()
        {
            cout<<"m : "<<m<<endl;
            cout<<"n : "<<n<<endl;
        }
};
integer :: integer(int x,int y)     //constructor defined
{
    m = x;
    n = y;
}
int main()
{
    integer i1(0,100);      //constructor called implicitly

    integer i2 = integer(25,75);        //constructor called explicitly

    cout<<"obj 1"<<endl;
    i1.display();

    cout<<"obj 2"<<endl;
    i2.display();
    
    return 0;
}
