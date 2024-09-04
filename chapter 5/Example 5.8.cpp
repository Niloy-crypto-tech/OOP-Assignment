#include <bits/stdc++.h>
using namespace std;

class test1;

class test2
{
    int a;

public:
    void setvalue(int x)
    {
        a = x;
    }
    friend void max(test1, test2);
};

class test1
{
    int b;

public:
    void setvalue(int y)
    {
        b = y;
    }
    friend void max(test1, test2);
};

void max(test1 me, test2 you)
{
    if (me.b >= you.a)
        cout << me.b << endl;
    else
        cout << you.a << endl;
}

int main()
{
    test2 obj;
    obj.setvalue(10);

    test1 objj;
    objj.setvalue(20);

    max(objj,obj);

    return 0;
}
