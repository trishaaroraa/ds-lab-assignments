#include <iostream>
using namespace std;

#define MAX 4

int main() {
    int a[MAX];

    cout << "Enter " << MAX << " diagonal elements:\n";
    for (int i = 0; i < MAX; i++)
        cin >> a[i];

    cout << "\nThe diagonal matrix is:\n";
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (i == j)
                cout << a[i] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}
