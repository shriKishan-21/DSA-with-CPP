#include <bits/stdc++.h>
using namespace std;


vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result(n, 1);

    // Compute prefix products
    int prefix = 1;
    for (int i = 0; i < n; i++)
    {
        result[i] = prefix;
        prefix *= nums[i];
    }

    // Compute suffix products and multiply with prefix
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        result[i] *= suffix;
        suffix *= nums[i];
    }

    return result;
}

int main()
{
    vector<int> nums = {-1,-1,-1,-1,-1,-1,-1,-1,-1};
    vector<int> ans = productExceptSelf(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}