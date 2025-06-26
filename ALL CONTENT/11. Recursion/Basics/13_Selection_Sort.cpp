#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[],int n){
    // base case
    if(n==0 || n==1){
        return ;
    }
    // solving 1 case
    int minIndex=0;
    for(int i=1;i<n;i++){
        if(arr[i]<arr[minIndex]){
            minIndex=i;
        }
    }
    swap(arr[0],arr[minIndex]);
    
    // recursive call
    selectionSort(arr+1,n-1);
}
int main()
{
    int arr[9] = {1,4,3,2,6,9,0,22,8};
    selectionSort(arr,9);
    for(int i=0;i<9;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}