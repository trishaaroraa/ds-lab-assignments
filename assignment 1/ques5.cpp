#include<iostream>
using namespace std;

void inputmatrix(int mat[100][100], int rows, int cols) {
    cout << "enter elements of the matrix:\n";
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }
}

void rowsum(int mat[100][100], int rows, int cols) {
    cout << "\nsum of each row\n";
    for(int i = 0; i < rows; i++) {
        int sum = 0;
        for(int j = 0; j < cols; j++) {
            sum += mat[i][j];
        }
        cout<<i+1<<":"<<sum <<endl;
    }
}

void colsum(int mat[100][100], int rows, int cols) {
    cout << "\nsum of each column\n";
    for(int j = 0; j < cols; j++) {
        int sum = 0;
        for(int i = 0; i < rows; i++) {
            sum += mat[i][j];
        }
        cout << j+1<< ":"<< sum << endl;
    }
}

int main() {
    int mat[100][100];
    int rows, cols;

    cout << "enter number of rows and columns ";
    cin >> rows >> cols;
	inputmatrix(mat, rows, cols);
    rowsum(mat, rows, cols);
    colsum(mat, rows, cols);

    return 0;
}
