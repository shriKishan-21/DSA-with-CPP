// PROBLEM EKO
// Lumberjack Mirko needs to chop down M metres of wood.
// It is an easy job for him since he has a nifty new woodcutting machine that can take down forests like wildfire.
// However, Mirko is only allowed to cut a single row of trees.

// Mirko‟s machine works as follows: Mirko sets a height parameter H (in metres),and
// the machine raises a giant sawblade to that height and
// cuts off all tree parts higher than H (of course, trees not higher than H meters remain intact). 
// Mirko then takes the parts that were cut off. 
// For example, if the tree row contains trees with heights of 20, 15, 10, and 17 metres, and Mirko raises his sawblade to 15 metres,
// the remaining tree heights after cutting will be 15, 15, 10, and 15 metres, respectively,
// while Mirko will take 5 metres off the first tree and 2 metres off the fourth tree (7 metres of wood in total).

// Mirko is ecologically minded, so he doesn‟t want to cut off more wood than necessary.
// That‟s why he wants to set his sawblade as high as possible.
// Help Mirko find the maximum integer height of the sawblade that still allows him to cut off at least M metres of wood.

// Input :

// The first line of input contains two space-separated positive integers, N (the number of trees, 1 ≤ N ≤ 1 000 000) and 
// M (Mirko‟s required wood amount, 1 ≤ M ≤ 2 000 000 000).
// The second line of input contains N space-separated positive integers less than 1 000 000 000, the heights of each tree (in metres).
// The sum of all heights will exceed M, thus Mirko will always be able to obtain the required amount of wood.

// Output :

// The first and only line of output must contain the required height setting.

#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &trees,int n, int m,int mid){
    int sum=0;
    int treeCount=1;
    for(int i=0;i<n;i++){
        if(trees[i]>=mid){
            if(trees[i]-mid<=m){
            sum+=(trees[i]-mid);
            if(sum>m){
                return false;
            }
        } 
    }   
    }
    return true;
}
int Eko(vector<int> &trees,int n, int m){
    sort(trees.begin(),trees.end());
    int s=0;
    int maxi=max(trees[0],trees[n-1]);
    int e=maxi;
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        if(isPossible(trees,n,m,mid)){
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
    // test case 1
    vector<int> arr1={20,15,10,17};
    int n1=arr1.size();//N=the number of trees
    int m1=7;//M=the required wood amount
    cout<<Eko(arr1,n1,m1);

    cout<<endl;
    // test case 2
    vector<int> arr2={4,42,40,26,46};
    int n2=arr2.size();//N=the number of trees
    int m2=20;//M=the required wood amount
    cout<<Eko(arr2,n2,m2);

}