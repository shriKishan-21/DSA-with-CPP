// TOTAL OCURRANCE OF ELEMENT IN AN ARRAY

#include <iostream>
using namespace std;

int firstOcc(int arr[],int n,int key){
    int s=0,e=n-1,ans=-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==key){
            ans=mid;
            e=mid-1;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
    return -1;
}

int lastOcc(int arr[],int n,int key){
    int s=0,e=n-1,ans=-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==key){
            ans=mid;
            s=mid+1;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
    return -1;
}

// total count = last - first + 1
int totalCount(int arr[],int n,int key){
    int first=firstOcc(arr,n,key);
    int last=lastOcc(arr,n,key);
    return last-first+1;
}

int main()
{
    int arr[]={1,2,3,3,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=3;
    cout<<totalCount(arr,n,target);
}
