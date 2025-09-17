#include<iostream>
using namespace std;
int insert(int arr[],int n,int val,int pos){
	if (pos<1 || pos>n+1) {
        cout <<"invalid position\n";
        return n;
    }
	for(int i=n-1;i>=pos-1;i--){
		arr[i+1]=arr[i];
	}
	arr[pos-1]=val;
	n++;
	return n;
}
int del(int arr[],int n,int val,int pos){
	if (pos<1 || pos>n) {
        cout <<"invalid position\n";
        return n;
    }
	for(int i=pos-1;i<n-1;i++){
		arr[i]=arr[i+1];
	}
	n--;
	return n;
}
int lsearch(int arr[],int n,int el){
	for(int i=0;i<n;i++){
		if(arr[i]==el){
			return i;
		}
	}
	return -1;
}
void display(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}
int main(){
	int arr[1000]={4,6,12,45,56};
	int n=5;
	int val=5,pos=2;
	display(arr,n);
	n=insert(arr,n,val,pos);
	display(arr,n);
	int el=56,position=6;
	n=del(arr,n,el,position);
	display(arr,n);
	int search=45;
	int idx=lsearch(arr,n,search);
	if(idx==-1)
    	cout<<"element not found";
    else
		cout<<"element is found at index "<<idx<<endl;
	return 0;
}
