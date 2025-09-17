#include <bits/stdc++.h>
using namespace std;

int countDistinct(vector<int>& arr) {
    int n = arr.size();

     sort(arr.begin(), arr.end());

    int distinctCount = 1; 
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            distinctCount++;
        }
    }
    return distinctCount;
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
    cout << "Total distinct elements: " << countDistinct(arr) << endl;
    return 0;
}
