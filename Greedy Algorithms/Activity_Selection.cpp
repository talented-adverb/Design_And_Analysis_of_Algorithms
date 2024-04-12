#include<iostream>
#include<algorithm>
using namespace std;

class ActivitySelection{
    public:
    int st , ft;

    
    // If you don't use the static keyword for the compare_ft function, you would need to call it on an instance of the ActivitySelection class. 
    //This would mean that you need to create an instance of the ActivitySelection class to call the compare_ft function.

    static bool compare_ft(ActivitySelection s1,ActivitySelection s2){ 
        return (s1.ft<s2.ft);
    }

    void activity(ActivitySelection arr[],int size){
        sort(arr,arr+size,compare_ft);

        cout<<"1: "<<arr[0].st<<"; "<<arr[0].ft<<endl;
        int pft=arr[0].ft;

        for(int i=1;i<size;i++){
            if(arr[i].st>pft)
            {
                cout<<i<<": "<<arr[i].st<<": "<<arr[i].ft<<endl;
                pft=arr[i].ft;
            }
        }
    }



};

int main(){
    ActivitySelection arr[]={{5,9},{1,2},{3,4},{0,6},{5,7},{8,9}};
    int size=sizeof(arr)/sizeof(arr[0]);

    arr[0].activity(arr,size);


}

// #include<iostream>
// #include<algorithm>
// using namespace std;

// class ActivitySelection {
// public:
//     int st, ft;

//     static bool compare_ft(const ActivitySelection s1, const ActivitySelection s2) {
//         return (s1.ft < s2.ft);
//     }

//     void activity(ActivitySelection arr[], int size) {
//         sort(arr, arr + size, compare_ft);

//         cout << "1: " << arr[0].st << ": " << arr[0].ft << endl;
//         int pft = arr[0].ft;

//         for (int i = 1; i < size; i++) {
//             if (arr[i].st >= pft) {
//                 cout << i + 1 << ": " << arr[i].st << ": " << arr[i].ft << endl;
//                 pft = arr[i].ft;
//             }
//         }
//     }
// };

// int main() {
//     ActivitySelection arr[] = { {5,9},{1,2},{3,4},{0,6},{5,7},{8,9} };
//     int size = sizeof(arr) / sizeof(arr[0]); // Calculate array size correctly

//     ActivitySelection obj;
//     obj.activity(arr, size);

//     return 0;
// }
