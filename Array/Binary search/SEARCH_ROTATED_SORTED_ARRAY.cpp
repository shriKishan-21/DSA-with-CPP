// SEARCH IN ROTATED SORTED ARRAY

#include<bits/stdc++.h>
using namespace std;

int getPivot(vector<int>& arr,int n){
    int s=0,e=n-1;
    int mid=s+(e-s)/2;
    while(s<e){
        if(arr[mid]>=arr[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return s;
}


int binarySearch(vector<int>& arr,int s,int e,int key){
    int start=s,end=e;
    int mid=start+(end-start)/2;
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
        mid=start+(end-start)/2;
    }
    return -1;
}

int findPosition(vector<int>& arr,int n,int key){
    int pivot=getPivot(arr,n);
    if(key>=arr[pivot] && key<=arr[n-1]){
        // binary seach on second half
        return binarySearch(arr,pivot,n-1,key);
    }
    else{
        // binary seach on first half
        return binarySearch(arr,0,pivot-1,key);
    }
}

int main(){
    vector<int> arr={5,6,1,2,4};
    int n=arr.size();
    int key=1;
    cout<<findPosition(arr,n,key)<<endl;
}