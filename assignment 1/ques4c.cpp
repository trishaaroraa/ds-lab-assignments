#include <iostream>
using namespace std;

void input(int mat[100][100], int n) {
    cout << "enter matrix elements:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
}

void output(int mat[100][100], int n) {
    cout << "matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void transpose(int mat[100][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
}

int main() {
    int n;
    cout << "size of square matrix: ";
    cin >> n;

    int mat[100][100];

    input(mat, n);

    cout << "\noriginal Matrix:\n";
    output(mat, n);

    transpose(mat, n);

    cout << "\ntransposed Matrix:\n";
    output(mat, n);

    return 0;
}
