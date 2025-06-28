#include<bits/stdc++.h>
using namespace std;

// -----------------------------------------------------------------------------------------------
/*
Approach 1 -->
using new array to store different parts
*/
// functioon to merge the arrays
void merge1(int *arr,int s,int e){
    // find mid
    int mid = (s+e)/2;

    // find length for the two arrays
    int len1 = mid - s + 1;
    int len2 = e - mid;

    // create new array of len1 and len2
    int *first = new int[len1];
    int *second = new int[len2];

    // copy the value of first part in first array
    int mainArrayIndex = s;
    for(int i=0;i<len1;i++){
        first[i]=arr[mainArrayIndex++];
    }

    // copy the value of second part in second array
    mainArrayIndex = mid+1;
    for(int i=0;i<len2;i++){
        second[i]=arr[mainArrayIndex++];
    }

    //merge
    // index for first array
    int index1 = 0;
    // index for second array
    int index2 = 0;
    // index of original array
    mainArrayIndex = s;

    // while loop to merge elements in sorted order in original array
    while(index1<len1 && index2 < len2){
        if(first[index1]<second[index2]){
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    // if the length of the the two array are not same , there can be elements left to be inserted 
    // so well seperately run while loop for both the arrays so that those elements can be inserted
    while(index1<len1){
        arr[mainArrayIndex++] = first[index1++];
    }
    while(index2<len2){
        arr[mainArrayIndex++] = second[index2++];
    }

    // delete the arrays
    delete []first;
    delete []second;

}

// function to sort the arrays
void mergeSort1(int *arr,int s,int e){
    // base case
    if(s>=e){
        return ;
    }
    int mid = (s+e)/2;

    //sort the left side 
    mergeSort1(arr,s,mid);

    // sort the right side
    mergeSort1(arr,mid+1,e);

    // merge the sorted arrays
    merge1(arr,s,e);
}

/*
TIME COMPLEXITY -->
Best Case : O(nlogn)
Average Case : O(nlogn)
Worst Case : O(nlogn)

SPACE COMPLEXITY --> O(n)
*/

// ---------------------------------------------------------------------------------

/*
Approach 2 -->
without creating new array
Using index
*/

void merge2(int *arr,int s,int e){
    // find mid
    int mid = (s+e)/2;

    int idx2 = mid + 1;

    // If already sorted, return
    if (arr[mid] <= arr[idx2])
        return;

    while (s <= mid && idx2 <= e) {
        // if s is smaller than idx2 i.e. start of first array is smaller so no need to update just go to next element
        if (arr[s] <= arr[idx2]) {
            s++;
        } 
        else {
            // if idx2 is smaller , shift the array from s to idx2 by 1 and update the value at idx2
            int value = arr[idx2];
            int index = idx2;

            // Shift all elements between s and idx2 right by 1
            while (index != s) {
                arr[index] = arr[index - 1];
                index--;
            }
            arr[s] = value;

            // Update all pointers
            s++;
            mid++;
            idx2++;
        }
    }
    // Here we use nested while loop which is not efficient
    // It may take O(n^2) time

}

void mergeSort2(int *arr,int s,int e){
    // base case
    if(s>=e){
        return ;
    }

    int mid = (s+e)/2;

    //sort the left side 
    mergeSort2(arr,s,mid);

    // sort the right side
    mergeSort2(arr,mid+1,e);

    // merge the sorted arrays
    merge2(arr,s,e);    

}

/*
TIME COMPLEXITY -->
Best Case : O(nlogn)
Average Case : O(n^2)
Worst Case : O(n^2)

SPACE COMPLEXITY --> O(1)
*/

// --------------------------------------------------------------------------------

int main()
{

    // For approach 1
    int arr[9] = {5,3,6,9,2,65,82,23,0};

    int n1 = 9;

    mergeSort1(arr,0,n1-1);

    cout<<"Sorted Array :"<<endl;
    for(int i=0;i<n1;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    // For approach 2
    int nums[12] = {34,64,26,6,8,3,0,8,4,1,56,87};
    int n2 = 12;

    mergeSort2(nums,0,n2-1);

    cout<<"Sorted Array :"<<endl;
    for(int i=0;i<n2;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;    
}