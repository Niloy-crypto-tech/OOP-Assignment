//An example with class

#include<iostream>
using namespace std;
class person {
    char name[30];
    int age;

public:
    void getdata();
    void display();
};
void person::getdata() {
    cout<<"Name:";
    cin>>name;
    cout<<"Age:";
    cin>> age;
}

void person::display() {
    cout<<"Name"<<name;
    cout<<"Age"<<age;
}

int main(){
    person a;
    a.getdata();
    a.display();

    return 0;
}

