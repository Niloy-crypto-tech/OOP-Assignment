#include <iostream>
using namespace std;

int main()
{
    float amount;
    float value(float p, int n, float r = 0.15);
    void printline(char ch = '*', int len = 40);

    printline(); // uses default values for arguments
    cout << endl;
    amount = value(5000.00, 5); // default for 3rd argument

    cout << "Final Value = " << amount << "\n";
    printline('+'); // use default value for 2nd argument
    return 0;
}
float value(float p, int n, float r)
{
    int year = 1;
    float sum = p;
    while (year <= n)
    {
        sum = sum * (1 + r);
        year = year + 1;
    }

    return (sum);
}
void printline(char ch, int len)
{
    for (int i = 1; i <= len; i++)
    {
        printf("%c", ch);
    }
}
