// BINARY SEARCH
#include<iostream>
using namespace std;

int binarySearch(int arr[],int n,int key){
    int start=0,end=n-1;
    int mid= start + (end-start)/2;
    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
        mid=start + (end-start)/2;
    }
    return -1;
}

int main(){
    int arr[]={1,3,5,7,9,11,13,15};
    int n=sizeof(arr)/sizeof(arr[0]);
    int key=7;
    cout<<binarySearch(arr,n,key)<<endl;
    return 0;
}