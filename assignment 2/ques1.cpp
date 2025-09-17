#include<iostream>
using namespace std;
int binsearch(int arr[],int s,int e,int n,int key){
    if(s>e){
        return -1;
    }
    int mid=s+(e-s)/2;
    if(arr[mid]==key){
        return mid;
    }
    else if(arr[mid]>key){
        return binsearch(arr,s,mid-1,n,key);
    }
    else{
        return binsearch(arr,mid+1,e,n,key);
    }
}

int main(){
    int arr[]={3,5,6,8,10,12,14};
    int n=sizeof(arr)/sizeof(arr[0]);
    int el=12,s=0,e=n-1;
    int idx=binsearch(arr,s,e,n,el);
    if(idx!=-1){
        cout<<"element found at index "<<idx<<endl;
        }
    else{
        cout<<"element not found"<<endl;
    }
    return 0;
}
