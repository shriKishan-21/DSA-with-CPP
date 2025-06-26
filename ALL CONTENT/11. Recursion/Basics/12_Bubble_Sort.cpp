#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[],int n){
    // base case
    if(n==0 || n==1){
        return ;
    }

    // solving 1 case - largest element at last
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    // recursive call
    bubbleSort(arr,n-1);
}
int main()
{
    int arr[5] = {5,4,3,2,1};
    
    bubbleSort(arr,5);

    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}