#include<iostream>
using namespace std;

void reverse(int arr[], int n) {
    int start=0, end=n-1;
    while (start<end) {
        
        int temp= arr[start];
        arr[start]= arr[end];
        arr[end]= temp;
        start++;
        end--;
    }
}

void display(int arr[], int n) {
    for (int i= 0;i< n;i++) {
        cout <<arr[i]<< " ";
    }
    cout << "\n";
}

int main() {
    int arr[1000] = {4, 5, 7, 1, 8, 9};
    int n=6;
    display(arr,n);
	reverse(arr,n);
	cout << "Reversed Array ";
    display(arr,n);

    return 0;
}
