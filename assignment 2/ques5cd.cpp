#include <iostream>
using namespace std;

#define MAX 4

int main() {
    int size = (MAX*(MAX+1))/2;
    int a[size];
    int k = 0;

    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++)
        cin >> a[i];

    cout << "\nThe Upper Triangular Matrix is:\n";
    k = 0;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (i <= j)
                cout << a[k++] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

    cout << "\nThe Lower Triangular Matrix is:\n";
    k = 0;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (i >= j)
                cout << a[k++] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}
