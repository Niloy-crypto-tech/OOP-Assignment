/*5.5: Create two classes DM and DB which store the value of distances. DM stores
distances in meters and centimeters and DB in feet and inches. Write a program
that can read values for the class objects and add one object of DM with another
object of DB.
Use a friend function to carry out the addition operation. The object that stores the
results may be a DM object or DB object, depending on the units in which the
results are required.
The display should be in the format of feet and inches or meters and centimeters
depending on the object on display. */

#include<iostream.h>
#define factor 0.3048
class DB;
class DM
{
 float d;
 public:
 void store(float x){d=x;}
 friend void sum(DM,DB);
 void show();
};
class DB
{
 float d1;
 public:
 void store(float y){d1=y;}
 friend void sum(DM,DB);
 void show();
};
void DM::show()
{
 cout<<"\n Distance = "<<d<<" meter or "<<d*100<<"
centimeter\n";
}
void DB::show()
{
 cout<<"\n Distance = "<<d1<<" feet or "<<d1*12<<" inches \n";
}
void sum(DM m,DB b)
{
 float sum;
 sum=m.d+b.d1*factor;
 float f;
 f=sum/factor;
 DM m1;
 DB b1;
 m1.store(sum);
 b1.store(f);
 cout<<" press 1 to display result in meter\n"
   <<" press 2 to display result in feet \n"
 <<" What is your option ? : ";
 int test;
 cin>>test;
 if(test==1)
 m1.show();
 else if(test==2)
 b1.show();
}
int main()
{
 DM dm;
 DB db;
 dm.store(10.5);
 db.store(12.3);
 sum(dm,db);
 return 0;
}
   
