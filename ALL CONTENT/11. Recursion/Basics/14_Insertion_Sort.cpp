#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int idx, int n){
    // base case
    if(idx==n){
        return ;
    }
    // solving 1 case
    int curr = arr[idx];
    int j = idx -1;
    while(j>=0 && arr[j]>curr){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=curr;

    // recursive call
    insertionSort(arr,idx+1,n);
}
int main()
{
    int arr[5] = {5,4,3,2,1};

    insertionSort(arr,1,5);
      
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}