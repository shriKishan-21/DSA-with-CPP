#include<bits/stdc++.h>
using namespace std;

int find(vector<int> &nums,int s,int e,int k){
    if(s>e) return -1;

    int mid=s+(e-s)/2;

    if(nums[mid]==k) return mid;

    if(nums[mid]>k) return find(nums,s,mid-1,k);
    else return find(nums,mid+1,e,k);
}

int search(vector<int> &nums, int target) {
    
    int ans = find(nums,0,nums.size(),target);

    return ans;
}
int main()
{
    vector<int> nums = {4, 5, 6, 7, 12, 19};
    int k = 12;
    int ans=search(nums,k);
    cout<<ans<<endl;
    return 0;

}