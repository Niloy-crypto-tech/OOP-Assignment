//5.3: Modify the class and the program of Exercise 5.1 for handling 10 customers
#include<bits/stdc++.h>
#define size 10
using namespace std;
char *serial[size]={" FIRST "," SECOND "," THIRD "," 4th "," 5th "," 6th "," 7th "," ","10th"};
class bank
{
 char name[40];
int ac_no;
 char ac_type[20];
 double balance;
public:
 int assign(void);
 void deposit(float b);
 void withdraw(float c);
 void displayon(void);
 void displayoff(void);
};
int bank::assign(void)
{
 float initial;
 cout<<" You have to pay 500 TK to open your account \n"
 <<" You have to store at least 500 TK to keep your account active\n"
 <<"Would you want to open a account????\n"
 <<" If Yes press 1 \n"
 <<" If No press 0 : ";
 int test;
 cin>>test;
 if(test==1)
 {
 initial=500;
 balance=initial;
cout<<" Enter name ,account number & account type to create account : \n";
 cin>>name>>ac_no>>ac_type;
 }
else
 ;// do nothing
 return test;
}
void bank::deposit(float b)
{
 balance+=b;
}
void bank::withdraw(float c)
{
 balance-=c;
 if(balance<500)
 {
 cout<<" Sorry your balance is not sufficient to withdraw "<<c<<"TK\n"
 <<" You have to store at least 500 TK to keep your account active\n";
 balance+=c;
 }
}
void bank::displayon(void)
{
 cout<<setw(12)<<name<<setw(17)<<ac_type<<setw(14)<<balance<<endl;
}
void bank::displayoff(void)
{ cout<<” Account has not created”<<endl; }
int main()
{
 bank account[size];
 int t[10];
 for(int i=0;i<size;i++)
 {
 cout<<" Enter information for "<<serial[i]<<"customer : "<<endl;
 t[i]=account[i].assign();
 if(t[i]==1)
 {
 cout<<" Would you want to deposit: ?"<<endl
 <<"If NO press 0(zero)"<<endl
 <<"If YES enter deposit amount :"<<endl;
 float dp;
 cin>>dp;
 account[i].deposit(dp);
 cout<<" Would you want to with draw : ?"<<endl
 <<"If NO press 0(zero)"<<endl
 <<"If YES enter withdrawal amount :"<<endl;
 float wd;
 cin>>wd;
 account[i].withdraw(wd);
 cout<<endl<<endl;
 }
 else if(t[i]==0)
 cout<<”Thank you , see again \n”;
 }
cout<<" see details :"<<endl<<endl;
 cout<<setw(12)<<"Name"<<setw(20)<<"Account type"
 <<setw(12)<<"Balance"<<endl;
 for(i=0;i<size;i++)
 {
 if(t[i]==1)
 account[i].displayon();
 else if(t[i]==0)
 account[i].displayoff();
 }
 return 0;
}
