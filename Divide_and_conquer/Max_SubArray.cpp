#include<iostream>
#include <bits/stdc++.h> 
using namespace std;

int max(int a,int b,int c){
    return max(max(a,b),c);
}

int cross_sum(int arr[], int st, int end,int mid){
    int left_sum=INT_MIN;
    int right_sum=INT_MIN;
    int sum1=0,sum2=0;
    for(int j=mid;j>=st;j--){
        sum1+=arr[j];
        if(sum1>left_sum) left_sum=sum1;
    }
    for(int j=mid+1;j<=end;j++){
        sum2+=arr[j];
        if(sum2>right_sum) right_sum=sum2;
    }
    return left_sum+right_sum;
}


int max_sub_array_sum(int arr[], int st, int end){
    if (end<st) return 0;
    else if (st==end) return arr[st];
    else
    {
        int mid= st + (end-st)/2;
        int leftsum=0;
        // for(int i=st;i<=mid;i++){
        //     leftsum+=arr[i];
        // }
        int rightsum=0;
        // for(int i=end;i>mid;i--){
        //     rightsum+=arr[i];
        // }   
        leftsum=max_sub_array_sum(arr, st, mid);
        rightsum=max_sub_array_sum(arr, mid+1, end);
        int cs=cross_sum(arr,st,end,mid);
        return max(leftsum,rightsum,cs);
    }




}

int main(){
    int arr[]={2,3,4,5,7};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<max_sub_array_sum(arr, 0, size-1);
}