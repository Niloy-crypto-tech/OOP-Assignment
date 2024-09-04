#include<bits/stdc++.h>
using namespace std;
class Time{
    int hour;
    int minutes;

    public:
        void gettime(int h,int m)
        {
            hour = h;
            minutes = m;
        }
        void puttime()
        {
            cout<<"hours : "<<hour<<endl;
            cout<<"minutes : "<<minutes<<endl;
        }
        void sum(Time t1,Time t2);       //decleration with obj as arguments
};
void Time :: sum(Time t1,Time t2)
{
    minutes = t1.minutes + t2.minutes;
    hour = minutes/60;
    minutes = minutes%60;
    hour = hour + t1.hour + t2.hour;
}
int main()
{
    Time T1,T2,T3;

    T1.gettime(2,45);
    T2.gettime(3,30);

    T3.sum(T1,T2);

    cout<<"T1"<<endl;
    T1.puttime();
    cout<<"T2<<endl";
    T2.puttime();
    cout<<"T3"<<endl;
    T3.puttime();
    
    return 0;
}
