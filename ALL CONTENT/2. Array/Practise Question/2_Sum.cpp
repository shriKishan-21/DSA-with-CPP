#include <iostream>
#include <stack>
#include <queue>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{

    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]] = i + 1;
    }

    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        if (mp[target - nums[i]] > 0)
        {
            ans.push_back(i);
            ans.push_back(mp[target - nums[i]] - 1);
            break;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = twoSum(nums, target);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}