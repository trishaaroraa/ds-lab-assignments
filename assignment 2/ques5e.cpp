#include <iostream>
using namespace std;

#define MAX 4

int main() {
    int size = (MAX*(MAX+1))/2;
    int a[size];
    int k = 0;

    cout << "Enter " << size << " elements of lower triangle:\n";
    for (int i = 0; i < size; i++)
        cin >> a[i];

    cout << "\nThe Symmetric Matrix is:\n";
    k = 0;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (i >= j)
                cout << a[(i*(i+1))/2 + j] << " ";
            else
                cout << a[(j*(j+1))/2 + i] << " ";  
        }
        cout << endl;
    }
    return 0;
}
