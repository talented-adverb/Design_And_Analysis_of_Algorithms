#include<iostream>
using namespace std;

int BS_Recursive(int l,int h,int key,int arr[]){
    if(l==h){
        if(arr[l]==key) return l;
        else return -1;
    }
    else{
        int mid=(l+h)/2;
        if(key==arr[mid]) return mid;
        else if(key>=arr[mid]) return BS_Recursive(mid+1,h,key,arr);
        else if(key<=arr[mid]) return BS_Recursive(l,mid-1,key,arr);
    }
}

int main(){
    int arr[]={3,6,8,12,14,17,25,29,31,36,42,47};
    int size=sizeof(arr)/sizeof(arr[0]);
    int e;
    cout<<"Enter the element that you want to find from the array\n";
    cin>>e;
    int index=BS_Recursive(0,size,e,arr);
    if(index!=-1) cout<<e<<" is Found";
    else cout<<"Element not found";
}