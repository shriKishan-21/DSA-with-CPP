// PAINTER PARTITION PROBLEM

#include<bits/stdc++.h>
using namespace std;    


bool isPossible(vector<int>& arr,int k,int mid){
    int paintersCount=1;
    int boardCount=0;
    for(int i=0;i<arr.size();i++){
        if(boardCount+arr[i]<=mid){
            boardCount+=arr[i];
        }
        else{
            paintersCount++;
            if(paintersCount>k || arr[i]>mid){
                return false;
            }
            boardCount=arr[i];
        }
    }
    return true;
}
int painterPart(vector<int>& arr,int k){
    int s=0;
    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
    }
    int e=sum;
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        if(isPossible(arr,k,mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}

int main(){
    vector<int> arr={10,20,30,40,50};
    int k=2;
    cout<<painterPart(arr,k);
}