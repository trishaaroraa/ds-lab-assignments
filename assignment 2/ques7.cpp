#include <iostream>
#include <vector>
using namespace std;

long long countInversions(vector<int>& arr) {
    int n = arr.size();
    long long invCount = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                invCount++;
            }
        }
    }
    return invCount;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Number of inversions: " << countInversions(arr) << endl;

    return 0;
}
