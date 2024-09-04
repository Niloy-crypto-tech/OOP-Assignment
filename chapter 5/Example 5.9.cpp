#include<bits/stdc++.h>
using namespace std;
class c2;

class c1{
    int val1;

    public:
        void indata(int a)
        {
            val1 = a;
        }
        void display()
        {
            cout<<val1<<endl;
        }
        friend void exchange(c1 &x,c2 &y);

};
class c2{
    int val2;

    public:
        void indata(int a)
        {
            val2 = a;
        }
        void display()
        {
            cout<<val2<<endl;
        }
        friend void exchange(c1 &x,c2 &y);
};
void exchange(c1 &x,c2 &y)
{
    int temp = x.val1;
    x.val1 = y.val2;
    y.val2 = temp;
}
int main()
{
    c1 obj1;
    c2 obj2;

    obj1.indata(100);
    obj2.indata(200);

    cout<<"values before exchange"<<endl;
    obj1.display();
    obj2.display();

    exchange(obj1,obj2);

    cout<<"values after exchange"<<endl;
    obj1.display();
    obj2.display();
    
    return 0;
}
