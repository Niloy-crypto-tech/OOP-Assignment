/* 3.3: Write a program to print the following outputs using for loops
        1
        22
        333
        4444
        55555
        ................ */
#include <iostream>
using namespace std;
int main() {     
    int n;
    cout<<" Enter your desired number :"<<endl;
    cin>>n;
    cout<<endl<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++) // here j always starts with 1 bcz everytime 'j<=i' occurs false it exits the inner loop 
            {
            cout<<i;
            }         
        cout<<endl;
        }
    return 0;
}
