#include <bits/stdc++.h>
using namespace std;

class node{
    public:
        node *left;
        node *right;
        char letter;
        int val;
        int code;
        node(int x,char y){
            letter=y;
            val=x;
            left=right=NULL;
        }
};

void sequencing(char l[],int f[],int s[],int size){
    sort(f,f+size);
    for(int i=0;i<size;i++){
        node(f[i],l[i]);
        s[i]=f[i];
    }
}

void TreeFormation(int s[],int size){
    node *n=new node(NULL,s[0]+s[1]);
    for(int i=2;i<size;i++){
        if
    }
}

int main(){
    char letters[7]={'a','e','i','o','u','s','t'};
    int freq[7]={10,15,12,3,4,13,1};
    int seq[7]={};
    int size=sizeof(letters)/sizeof(letters[0]);
    sequencing(letters,freq,seq,size);
}