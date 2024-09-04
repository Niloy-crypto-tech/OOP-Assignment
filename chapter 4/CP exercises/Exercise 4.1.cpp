#include <iostream>
using namespace std;

int main()
{
    int m, n;
    cout << "Enter the number of rows and columns: ";
    cin >> m >> n;

    int matrix[m][n];
    cout << "Enter the elements: ";
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> matrix[i][j];
        }
    }
    cout<<"succesfully read a amtrix from the keyboard!"<<endl;

    return 0;
}
