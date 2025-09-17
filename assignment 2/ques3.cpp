#include<iostream>
using namespace std;
int lsearch(int arr[],int n){
    int expectedSum = (n * (n + 1)) / 2;
    int actualSum = 0;

    for (int i = 0; i < n - 1; i++) {
        actualSum += arr[i];
    }

    return expectedSum - actualSum;
}
int binsearch(int arr[],int s,int e,int n){
    int missing=-1;
    while (s <= e) {
        int mid = s + (e- s) / 2;

        if (arr[mid] == mid + 1) {
            s = mid + 1;
        } else {
            missing = mid + 1;
            e = mid - 1;
        }
    }
    return missing;
}

int main(){
    int arr[]={2,3,4,5,6,7,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    int missing=lsearch(arr,n);
    cout<<"missing element (though linear search) is:"<<missing<<endl;
    int s=0,e=n-1;
    int missingBinSearch=binsearch(arr,s,e,n);
    cout<<"missing element(through binary search) is:"<<missingBinSearch<<endl;
    return 0;
}
