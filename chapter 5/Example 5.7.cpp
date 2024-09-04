#include <bits/stdc++.h>
using namespace std;
class sample
{
    int a;
    int b;

public:
    void setval()
    {
        a = 25;
        b = 40;
    }
    friend float mean(sample s);
};
float mean(sample s)
{
    return float(s.a + s.b) / 2.0;
}
int main()
{
    sample x;
    x.setval();

    cout << "mean value = " << mean(x) << endl;

    return 0;
}
