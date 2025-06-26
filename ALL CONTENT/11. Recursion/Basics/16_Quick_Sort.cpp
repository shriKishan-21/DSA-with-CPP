#include<bits/stdc++.h>
using namespace std;


int partition(int arr[],int s,int e){
    // find pivot
    int pivot = arr[s];

    // count elements smaller than pivot
    int count = 0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<pivot){
            count++;
        }
    }

    // place pivot at right position
    int pivotIndex = s+count;
    swap(arr[pivotIndex],arr[s]);

    // maintain the condition of left < pivot < right
    int i=s , j=e;
    while(i<pivotIndex && j>pivotIndex){
        // using if else if else loop is inefficient 
        // so usimg while loop is more efficient
        while(arr[i]<pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }

    return pivotIndex;
}

void quickSort(int arr[],int s,int e){
    // base case
    if(s>=e){
        return ;
    }

    int p = partition(arr,s,e);

    // recursive call
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);

}


/*
TIME COMPLEXITY -->
best case -> O(nlogn)
average case -> O(nlogn)
worst case -> O(n^2)

space complexity -> O(logn)
*/


int main()
{
    int arr[5] = {1,4,16,6,9};
    int n =5;

    quickSort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}