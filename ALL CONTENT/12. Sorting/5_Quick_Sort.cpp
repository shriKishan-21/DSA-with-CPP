#include<bits/stdc++.h>
using namespace std;


// ----------------------------------------
// Method 1
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

// -------------------------------------------------------------
// In - place quick sort
int partition2(int arr[],int s,int e){
    int pivot = arr[e];
    int i = s-1;
    for(int j =s ;j<=e;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[e]);
    return i+1;
}

void quickSort2(int arr[] , int s , int e){
    if(s>=e){
        return ;
    }
    int p = partition2(arr,s,e);
    
    quickSort2(arr,s,p-1);
    quickSort2(arr,p+1,e);
    
}

/*
TIME COMPLEXITY -->
best case -> O(nlogn)
average case -> O(nlogn)
worst case -> O(n^2)

space complexity ->
best case -> O(logn)
average case -> O(logn)
worst case -> O(n)
*/

// ----------------------------------------------------------------
int main()
{
    // Method 1
    int arr[5] = {1,4,16,6,9};
    int n =5;
    
    quickSort(arr,0,n-1);
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    // Method 2
    int arr2[5] = {1,4,16,6,9};
    int n2 =5;
    
    quickSort2(arr2,0,n2-1);
    
    for(int i=0;i<n2;i++){
        cout<<arr2[i]<<" ";
    }

    return 0;
}


/*
TIME COMPLEXITY -->
best case -> O(nlogn)
average case -> O(nlogn)
worst case -> O(n^2)

space complexity -> O(logn)
*/