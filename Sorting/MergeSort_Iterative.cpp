#include<iostream>
using namespace std;

int* MergeSort_iterative(int a[],int b[],int s_a,int s_b){
    int i,j,k;
    i=j=k=0;
    int *mergedArr =new int[s_a+s_b];
    while(i<s_a && j<s_b){
        if(a[i]<b[j]) mergedArr[k++]=a[i++];
        else if(a[i]==b[j]) mergedArr[k++]=a[i++];
        else mergedArr[k++]=b[j++];
    }

    for(i;i<s_a;i++){
        mergedArr[k++]=a[i];
    }
    for(j;j<s_b;j++){
        mergedArr[k++]=b[j];
    }
    return mergedArr;
}

int main(){
    int a[]={2,8,15,18};
    int b[]={5,9,12,17,19,20,25};
    int size_a=sizeof(a)/sizeof(a[0]);
    int size_b=sizeof(b)/sizeof(b[0]);
    int *MergedarrPointer=MergeSort_iterative(a,b,size_a,size_b);
    int size_c=size_a+size_b;
    for(int z=0;z<size_c;z++){
        cout<<MergedarrPointer[z]<<endl;
    }
    delete[] MergedarrPointer;
}