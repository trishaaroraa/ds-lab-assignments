#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void heapifyMax(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapifyMax(arr, n, largest);
    }
}

void heapifyMin(int arr[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] < arr[smallest])
        smallest = left;

    if(right < n && arr[right] < arr[smallest])
        smallest = right;

    if(smallest != i) {
        swap(arr[i], arr[smallest]);
        heapifyMin(arr, n, smallest);
    }
}

void heapSortIncreasing(int arr[], int n) {
    for(int i = n/2 - 1; i >= 0; i--)
        heapifyMax(arr, n, i);

    for(int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapifyMax(arr, i, 0);
    }
}

void heapSortDecreasing(int arr[], int n) {
    for(int i = n/2 - 1; i >= 0; i--)
        heapifyMin(arr, n, i);

    for(int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapifyMin(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main() {
    int arr[] = {45, 12, 78, 34, 56, 9, 23};
    int n = 7;

    cout << "Original Array: ";
    printArray(arr, n);

    heapSortIncreasing(arr, n);
    cout << "\nIncreasing Order: ";
    printArray(arr, n);

    int arr2[] = {45, 12, 78, 34, 56, 9, 23};

    heapSortDecreasing(arr2, n);
    cout << "\nDecreasing Order: ";
    printArray(arr2, n);

    return 0;
}
