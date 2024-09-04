#include <iostream>
using namespace std;

void readMatrix(int m, int n, int matrix[][10]) {
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(int m, int n, int matrix[][10]) {
    cout << "The matrix is:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int m, n;
    cout << "Enter the number of rows and columns (less than 10): ";
    cin >> m >> n;

    int matrix[10][10]; 
    readMatrix(m, n, matrix);
    displayMatrix(m, n, matrix);

    return 0;
}
