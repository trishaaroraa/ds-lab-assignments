#include<iostream>
using namespace std;

void multiplymatrices(int A[2][3], int B[3][2], int C[2][2]) {
    for (int i=0; i<2;i++) {
        for (int j=0;j<2;j++) {
            C[i][j]=0;
            for(int k=0;k<3;k++) {
                C[i][j]+= A[i][k]*B[k][j];
            }
        }
    }
}
int main(){
    int A[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
	int B[3][2] = {
        {7, 8},
        {9, 10},
        {11, 12}
    };
	int C[2][2];
	multiplymatrices(A,B,C);
	cout << "resultant matrix\n";
    for (int i = 0;i <2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << C[i][j]<< " ";
        }
        cout << "\n";
    }

    return 0;
}
