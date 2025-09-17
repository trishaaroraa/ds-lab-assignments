#include <iostream>
using namespace std;

#define MAX 4

int main() {
    int size = 3*MAX - 2;
    int a[size];  
    int k = 0;

    cout << "Enter " << size << " tri-diagonal elements:\n";
    for (int i = 0; i < size; i++)
        cin >> a[i];

    cout << "\nThe tri-diagonal matrix is:\n";
    k = 0;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (i - j == -1 || i - j == 0 || i - j == 1) {
                cout << a[k++] << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    return 0;
}
