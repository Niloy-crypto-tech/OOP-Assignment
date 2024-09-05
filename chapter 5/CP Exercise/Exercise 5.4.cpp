/*5.4: Modify the class and the program of Exercise 5.12 such that the program
would be able to add two vectors and display the resultant vector. (Note that we
can pass objects as function arguments) */

#include<iostream.h>
#include<iomanip.h>
#define size 8
class vector
{
 float *p;
public:
 void creat_vector(void);
 void set_element(int i,float value);
 friend void add(vector v1,vector v2);
};
void vector::creat_vector(void)
{
 p=new float[size];
}
void vector::set_element(int i,float value)
{
 p[i]=value;
}
void add(vector v1,vector v2)
{
 float *sum;
 cout<<"sum["<<size<<"] = (";
 sum= new float[size];
 for(int i=0;i<size;i++)
 {
 sum[i]=v1.p[i]+v2.p[i];
 if(i==size-1)
 cout<<sum[i];
 else
 cout<<sum[i]<<" , ";
 }
 cout<<")"<<endl;
}
int main()
{
 vector x1,x2,x3;
 x1.creat_vector();
 x2.creat_vector();
 x3.creat_vector();
 cout<<" Enter "<<size<<" elements of FIRST vector : ";
 for(int i=0;i<size;i++)
   {
 float v;
 cin>>v;
 x1.set_element(i,v);
 }
 cout<<" Enter "<<size<<" elements of SECOND vector : ";
 for(i=0;i<size;i++)
 {
 float v;
 cin>>v;
 x2.set_element(i,v);
 }
 add(x1,x2);
 return 0;
}
