// SELECTION SORT

#include<bits/stdc++.h>
using namespace std;

bool selectionSort(vector<int> &arr,int n){
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        swap(arr[minIndex],arr[i]);
    }
}

int main(){
    vector<int> arr={5,4,3,2,1};
    int n=arr.size();
    selectionSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}


// WHERE TO USE :
// array/vector/list all have small size

// // TIME COMPLEXITY :
// (1) Best case --> O(n^2)
// (2) Average case --> O(n^2)
// (3) Worst case --> O(n^2)