#include<bits/stdc++.h>
using namespace std;
class Complex{
    float x;
    float y;

    public:
        void input(float real,float imag)
        {
            x = real;
            y = imag;
        }
        friend Complex sum(Complex c1,Complex c2);
        void show(Complex c1);
};
Complex sum(Complex c1,Complex c2)
{
    Complex c3;
    c3.x = c1.x + c2.x;
    c3.y = c1.y + c2.y;

    return c3;
}
void Complex :: show(Complex c1)
{
    cout<<c1.x<<" + j"<<c1.y<<endl;
}
int main()
{
    Complex A,B,C;

    A.input(3.1,5.65);
    B.input(2.75,1.2);

    C = sum(A,B);

    cout<<"A"<<endl;
    A.show(A);
    cout<<"B"<<endl;
    B.show(B);
    cout<<"C"<<endl;
    C.show(C);
    
    return 0;
}
