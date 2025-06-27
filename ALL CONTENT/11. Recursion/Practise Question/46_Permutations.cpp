#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> nums, int index, vector<vector<int>> &ans)
{
    if (index >= nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        solve(nums, index + 1, ans);
        // backtrack
        // as we are making changes in original array so we need to make sure while going back the
        // array should be original and do not change so that the next recursive call will be correct
        swap(nums[index], nums[i]);
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    int index = 0;

    solve(nums, index, ans);

    return ans;
}
int main()
{
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> ans = permute(nums);
    
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}