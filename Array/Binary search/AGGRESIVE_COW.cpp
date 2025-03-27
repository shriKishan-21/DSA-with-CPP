// AGGRESSIVE COWS PROBLEM

#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &stalls,int k,int mid){
    int cowCount=1;
    int stallCount=stalls[0];
    for(int i=0;i<stalls.size();i++){
        if(stalls[i]-stallCount>=mid){
            cowCount++;
            if(cowCount==k){
                return true;
            }
            stallCount=stalls[i];
        }
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k){
    sort(stalls.begin(),stalls.end());
    int s=0;
    int maxi=max(stalls[0],stalls[stalls.size()-1]);
    int mini=min(stalls[0],stalls[stalls.size()-1]);
    int e=maxi-mini;
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        if(isPossible(stalls,k,mid)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
int main(){
    vector<int> stalls={1,2,3,4,6};
    int k=2;
    cout<<aggressiveCows(stalls,k);
}