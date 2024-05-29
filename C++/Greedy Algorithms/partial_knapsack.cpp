#include<iostream>
#include<algorithm>
using namespace std;

class p_knapsack{
    public:
    double profit,weight;
    int no;

    p_knapsack(double prof, double w,int n){
        this->weight=w;
        this->profit=prof;
        this->no=n;
    }
};

bool cmp(p_knapsack p1,p_knapsack p2){
    double p_1=p1.profit/p1.weight;
    double p_2=p2.profit/p2.weight;
    return p_1>p_2;
}

double items_included(p_knapsack p[],int size,int w){
    int p_sum=0;
    for(int i=0;i<size;i++){
        if(p[i].weight<=w){
            p_sum+=p[i].profit;
            w-=p[i].weight;
            cout<<p[i].no<<" ";
        }
        else{
            double par_p=p[i].profit*(w/p[i].weight);
            p_sum+=par_p;
            cout<<p[i].no<<" ";
            break;
        }
    }
    return p_sum;
}



int main(){
    p_knapsack p_objects[] = { { 60, 10,1 }, { 100, 20,2 }, { 120, 30,3 } };
    int W=50;
    int size=sizeof(p_objects)/sizeof(p_objects[0]);
    sort(p_objects,p_objects+size,cmp);
    cout<<items_included(p_objects,size,W)<<endl;
}