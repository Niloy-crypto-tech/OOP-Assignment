#include <bits/stdc++.h>
using namespace std;
class item
{
    static int count;
    int num;

public:
    void getdata(int a)
    {
        num = a;
        count++;
    }
    void getcount()
    {
        cout << "count : " << count << endl;
    }
};
int item ::count;       //defination of static data member
int main()
{
    item a, b;

    a.getcount();
    b.getcount();

    a.getdata(100);
    b.getdata(200);

    cout << "After reading data" << endl;
    a.getcount();
    b.getcount();

    return 0;
}
