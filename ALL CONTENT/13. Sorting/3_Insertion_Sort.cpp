#include<bits/stdc++.h>
using namespace std;

// using nested loops
void insertionSort1(int arr[],int n){
    
    for(int i=1;i<n;i++){
        int temp = arr[i];
        int j = i-1;
        for(;j>=0;j--){
            if(arr[j]>temp){
                // shift j
                arr[j+1] = arr[j];
                // if array is [5,4,3,2,1] then arr[j+1] = arr[j] will make array
                // array [5,5,3,2,1]
            }
            else{
                // do nothing(already sorted)
                break;
            }
        }
        /* 
           THIS IS JUST AN EXAMPLE :
           if array is : [5,4,3,2,1]
           for i =0 , temp will be 4
           coming out of loop j will be j will be -1
           so arr[j+1] = arr[j] will make array
           array [4,5,3,2,1]
        */
        arr[j+1] = temp;
    }
}

// using while loop 
void insertionSort2(int nums[],int n){
    
    for(int i=1;i<n;i++){
        int temp = nums[i];
        int j = i-1;
        while(j>=0 && nums[j]>temp){
            // shift j
            nums[j+1] = nums[j];
            // update j
            j--;
        }
        // place temp at right position
        nums[j+1] = temp;
    }
}
int main()
{
    int arr[] = {5,4,3,2,1};

    // using nested loops
    insertionSort1(arr,5);
    cout<<"Using nested loops -->"<<endl;
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
    int nums[] = {9,7,0,3,1};
    // using while loop
    insertionSort2(nums,5);
    cout<<"Using while loop -->"<<endl;
    for(int i=0;i<5;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}