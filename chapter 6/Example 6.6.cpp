#include<bits/stdc++.h>
using namespace std;

int cnt = 0; 

class alpha
{
public:
    alpha()
    {
        cnt++;
        cout << "Number of objects created: " << cnt << endl;
    }

    ~alpha()
    {
        cout << "Number of objects destroyed: " << cnt << endl;
        cnt--;
    } 
};

int main()
{
    cout << "Enter main" << endl;
    alpha a1, a2, a3, a4;

    {
        cout << "Enter block 1" << endl;
        alpha a5;
    }

    {
        cout << "Enter block 2" << endl;
        alpha a6;
    }

    cout << "Re-enter main" << endl;
    
    return 0;
}
