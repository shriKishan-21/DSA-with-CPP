// COOKING NINJAS

// In Ninja Land, there is a famous restaurant named ‘CookingNinjas’.
// There are ‘N’ cooks in ‘CookingNinjas’ numbered from 0 to N-1.
// Each cook has rank ‘R’ (1 <= R <= 10).

// A cook with a rank ‘R’ can prepare 1 dish in the first ‘R’ minutes, 1 more dish in the next ‘2R’ minutes,
// 1 more dish in next ‘3R’ minutes, and so on (A cook can only make complete dishes) For example if a cook is ranked 2.
// He will prepare one dish in 2 minutes, one more dish in the next 4 mins and
// one more in the next 6 minutes hence in a total of 12 minutes he can make 3 dishes,
// Note, In 13 minutes also he can make only 3 dishes as he does not have enough time for the 4th dish).

// One day ‘CookingNinjas’ receive an order of ‘M’ dishes that they need to complete as early as possible.
// You are given an integer array ‘rank’ of size ‘N’ in which ‘rank[i]’ gives ‘rank’ of ith cook and an integer ‘M’,
// You need to find out the minimum times required to complete this order of ’M’ dishes.

// Note
// One dish can be prepared by only one cook, however, two or more cooks can simultaneously prepare different dishes.

#include<bits/stdc++.h>
using namespace std;

bool isPossible (vector<int>& arr,int n,int m,int mid){
    int count=0;
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(arr[i]);
        }
    }
}

int cookingNinjas(vector<int>& arr,int n,int m){
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        if(isPossible(arr,n,m,mid)){
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
    vector<int> arr={1,2,3,4};
    int n=arr.size();
    int m=11;
    cout<<cookingNinjas(arr,n,m);
    return 0;
}



