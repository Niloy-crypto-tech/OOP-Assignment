
#include <bits/stdc++.h>
using namespace std;

class Set
{
    int m, n;

public:
    void input()
    {
        cout << "inputting values of m & n" << endl;
        cin >> m >> n;
    }
    int largest()
    {
        if (m >= n)
            return m;
        else
            return n;
    }

    void display()
    {
        cout << "Largest is " << largest() << endl; 
    }
};

int main()
{
    Set A;
    A.input();
    A.display();
    return 0;
}
