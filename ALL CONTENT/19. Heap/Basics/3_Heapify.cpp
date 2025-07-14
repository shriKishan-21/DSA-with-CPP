#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

void heapify(vector<int> &arr,int n,int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    // check if left child is largest
    if(left<n && arr[largest]<arr[left]){
        largest = left;
    }
    // check if right child is largest
    if(right<n && arr[largest]<arr[right]){
        largest = right;
    }

    // swap
    if(largest!=i){
        swap(arr[i],arr[largest]);
        // recursive call -- to check further
        heapify(arr,n,largest);
    }
}

vector<int> buildMaxHeap(vector<int> &arr){
    int n = arr.size();
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
    return arr;
}

int main()
{
    vector<int> arr = {-1,54,55,53,52,50};
    arr = buildMaxHeap(arr);
    for(int i=1;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    
    
    return 0;

}