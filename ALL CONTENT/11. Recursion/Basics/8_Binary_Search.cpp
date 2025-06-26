#include<bits/stdc++.h>
using namespace std;


bool binarySearch(int arr[],int s, int e ,int key){
    // base case
    if(s>e) return false;

    int mid = s+(e-s)/2;

    if(arr[mid]==key){
        return true;
    }

    // recursion
    if(arr[mid]>key){
        return binarySearch(arr,s,mid-1,key);
    }
    else{
        return binarySearch(arr,mid+1,e,key);
    }
}
int main()
{
    int arr[6] = {1,2,3,4,5,6};
    int size = 6;
    int key = 3;
    cout<<binarySearch(arr,0,size,key);
}