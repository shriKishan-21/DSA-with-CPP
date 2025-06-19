// BUBBLE SORT

#include <bits/stdc++.h>
using namespace std;

bool bubbleSort(vector<int> &arr,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

// OPTIMISED APPROACH

bool bubbleSort(vector<int> &arr,int n){
    bool swapped=false;
    for(int i=0;i<n;i++){
        bool swapped=false;
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
    }
    if(swapped==false){
        return false;
    }
    else{
        return true;
    }
}

int main(){
    vector<int> arr={1,2,3,4};
    int n=arr.size();
    bubbleSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

// TIME COMPLEXITY :

// (1) Best case--> O(n)
// (2) Average case--> O(n^2)
// (3) Worst case--> O(n^2)

