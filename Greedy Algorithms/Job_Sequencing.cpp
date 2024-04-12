#include<iostream>
#include<algorithm>
using namespace std;

class Job_Seq{
    public:
    int jid, dead, profit;
};
bool comp_profit( Job_Seq j1, Job_Seq j2){
    return (j1.profit>j2.profit);
}
void job_sch( Job_Seq arr[], int size)   //brackets daalna yaad rakhna array ke aage
{
    sort(arr, arr+size, comp_profit);

    int result[size]={0};
    int slot[size]={0};
    for (int i=0; i<size; i++)
    {

        for (int j=min(size, arr[i].dead)-1; j>=0; j--)
        {
            if(slot[j]==0)
            {
                result[j]=arr[i].jid;
                slot[j]=1;
                break;
            }
        }
    }

    for(int i=0; i<size; i++){   
        if(result[i]!=0) cout<<result[i]<<"\t";
    }

}
int main(){

    Job_Seq arr[]={{1,2,100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 3, 15}};
    int size= sizeof(arr)/sizeof(arr[0]);

    job_sch(arr, size);
}
