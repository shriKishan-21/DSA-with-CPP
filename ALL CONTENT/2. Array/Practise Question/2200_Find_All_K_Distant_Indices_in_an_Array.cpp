#include <bits/stdc++.h>
using namespace std;

vector<int> findKDistantIndices(vector<int> &nums, int key, int k)
{
    vector<int> ans;
    vector<int> keyIndex;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == key)
        {
            keyIndex.push_back(i);
        }
    }
    for (int i = 0; i < nums.size() ; i++)
    {
        for (int j = 0; j < keyIndex.size(); j++)
        {
            if (abs(i - keyIndex[j]) <= k )
            {
                ans.push_back(i);
            }
        }
    }
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    return ans;
}

int main(){
    vector<int> nums={2,2,2,2,2};
    int key=2;
    int k=2;
    vector<int> ans=findKDistantIndices(nums,key,k);
    cout<<"Answer is: ";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}