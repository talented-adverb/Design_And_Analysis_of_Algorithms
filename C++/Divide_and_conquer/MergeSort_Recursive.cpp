#include<iostream>
using namespace std;

void Merge(int arr[],int l, int mid, int h){
    int i,j,k;
    i=j=k=0;
    int n1=mid-l;
    int n2=h-mid;
    int L1[n1],L2[n2];
    for(int a=0;a<n1;a++){
        L1[a]=arr[a];
    }
    for(int b=0;b<n2;b++){
        L2[b]=arr[b];
    }
    int *mergedArr =new int[n1+n2];
    while(i<n1 && j<n2){
        if(L1[i]<L2[j]) mergedArr[k++]=L1[i++];
        else if(L1[i]==L2[j]) mergedArr[k++]=L1[i++];
        else mergedArr[k++]=L2[j++];
    }

    for(i;i<n1;i++){
        mergedArr[k++]=L1[i];
    }
    for(j;j<n2;j++){
        mergedArr[k++]=L2[j];
    }
}

void MergeSort_Recursive(int arr[],int l,int h){
    if(l<h){
        int mid=(l+h)/2;
        MergeSort_Recursive(arr,l,mid);
        MergeSort_Recursive(arr,mid+1,h);
        Merge(arr,l,mid,h);
    }
}

int main(){
    int arr[]={1,4,2,341,23,414,233};
    int size=sizeof(arr)/sizeof(arr[0]);
    MergeSort_Recursive(arr,0,size-1);
}