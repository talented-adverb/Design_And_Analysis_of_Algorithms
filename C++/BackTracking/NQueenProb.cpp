#include<iostream>
using namespace std;

int arr[4]={5 };
int size=sizeof(arr)/sizeof(arr[0]);
void print(){
    for(int i=0;i<size;i++){
        cout<<arr[i];
    }
}

bool place(int q,int col){
    for(int j=0;j<q;j++){
        if((arr[j]==col) || (abs(arr[j]-col))==(abs(j-q))) return false;
    }
    return true;
}

void back_track(int q){
    for(int i=0;i<size;i++){
        if(place(q,i)){
            arr[q]=i;
            if(q==size-1) print();
            else back_track(q+1);
        }
    }
}

int main(){
    back_track(0);
}