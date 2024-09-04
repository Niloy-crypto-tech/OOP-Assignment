#include<bits/stdc++.h>
using namespace std;
class Complex{
    float x;
    float y;

    public:
        Complex(){};        //constructor with no arg
        Complex(float a)        //constructor with one arg
        {
            x = y = a;
        }
        Complex(float real,float imag)      //constructor with two arg
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
    Complex A(2.7,3.5);
    Complex B(1.6);
    Complex C;

    C = sum(A,B);

    cout<<"A"<<endl;
    A.show(A);
    cout<<"B"<<endl;
    B.show(B);
    cout<<"C"<<endl;
    C.show(C);
    
    return 0;
}
