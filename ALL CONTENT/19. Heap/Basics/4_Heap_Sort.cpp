#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;


void heapify(int arr[],int n,int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    // check if left child is largest
    if(left<=n && arr[largest]<arr[left]){
        largest = left;
    }
    // check if right child is largest
    if(right<=n && arr[largest]<arr[right]){
        largest = right;
    }

    // swap
    if(largest!=i){
        swap(arr[i],arr[largest]);
        // recursive call -- to check further
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[] , int n){

    int size = n;
    // heap sort
    while(size>1){
        // step 1 : swap root with last node
        swap(arr[1],arr[size]);
        // step 2 : delete last node
        size--;
        // step 3 : heapify root node
        heapify(arr,size,1);
    }
}

int main()
{
    int arr[] = {-1,54,53,55,52,50};
    int n = 5; // -- 1 based indexing

    // heap creation
    for(int i = n/2; i>0 ; i--){ // O(N) time -- heapify operation
        heapify(arr,n,i);
    }
    cout<<"Printing Heap"<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    // heap sort
    heapSort(arr,n);
    cout<<"Printing Sorted Heap"<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    
    
    return 0;

}