#include <iostream>
#define MAX(a, b, c) ((a > b && a > c) ? a : (b > c ? b : c))

using namespace std;

int main() {
    int a, b, c;
    cout << "Enter three numbers: ";
    cin >> a >> b >> c;

    cout << "The largest number is: " << MAX(a, b, c) << endl;

    return 0;
}
