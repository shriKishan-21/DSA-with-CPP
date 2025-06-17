#include <bits/stdc++.h>
using namespace std;

// With extra space
vector<int> buildArrayWithSpace(vector<int> &nums)
{
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        ans.push_back(nums[nums[i]]);
    }
    return ans;
}


// Without extra space

vector<int> buildArrayWithoutSpace(vector<int> &nums)
{
    int n = nums.size();
    for(int i=0;i<n;i++){
        nums[i] = nums[i]+n*(nums[nums[i]]%n);
    }
    for(int i=0;i<n;i++){
        nums[i] = nums[i]/n;
    }
    return nums;
}
int main()
{
    vector<int> nums = {0, 2, 1, 5, 3, 4};
    vector<int> ans1 = buildArrayWithSpace(nums);
    cout<<"With extra space"<<endl;
    for (int i = 0; i < ans1.size(); i++)
    {
        cout << ans1[i] << " ";
    }
    cout << endl;
    cout<<"Without extra space"<<endl;
    vector<int> ans2 = buildArrayWithoutSpace(nums);
    for (int i = 0; i < ans2.size(); i++)
    {
        cout << ans2[i] << " ";
    }
}