#include<iostream>
using namespace std;

int BS_interative(int l,int h,int key,int arr[]){
    int size=h+1;
    int mid;
    while(l<=h){
        mid=(l+h)/2;
        if(key==arr[mid]) return mid;
        else if(key<arr[mid]) h=mid-1;
        else if(key>arr[mid]) l=mid+1;
    }
    return -1;
}

int main(){
    int arr[]={3,6,8,12,14,17,25,29,31,36,42,47};
    int size=sizeof(arr)/sizeof(arr[0]);
    int e;
    cout<<"Enter the element that you want to find from the array\n";
    cin>>e;
    int index=BS_interative(0,size-1,e,arr);
    if(index!=-1) cout<<arr[index]<<" is Found";
    else cout<<"Element not found";
}