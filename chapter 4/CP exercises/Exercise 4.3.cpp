#include <iostream>
using namespace std;

void readMatrix(int n, int matrix[][10], int m = 3) {  
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(int n, int matrix[][10], int m = 3) {  
    cout << "The matrix is:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, m = 3;  // Default rows = 3
    cout << "Enter the number of columns: ";
    cin >> n;

    int matrix[10][10];
    readMatrix(n, matrix, m);
    displayMatrix(n, matrix, m);

    return 0;
}
