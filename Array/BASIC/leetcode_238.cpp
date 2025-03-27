#include <bits/stdc++.h>
using namespace std;

int calculate(vector<int> &nums, int num)
{
    int zero = 0;
    int j = 0;
    int product = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            zero++;
        }
    }
    if (zero > 1)
    {
        return product = 0;
    }
    else
    {

        while (j < nums.size())
        {
            if (nums[j] == num && j < nums.size())
            {
                j++;
            }
            if (j < nums.size())
            {
                product = product * nums[j];
            }
            j++;
        }
        return product;
    }
}

vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        ans.push_back(calculate(nums, nums[i]));
    }
    return ans;
}

// vector<int> productExceptSelf(vector<int> &nums)
// {
//     int n = nums.size();
//     vector<int> result(n, 1);

//     // Compute prefix products
//     int prefix = 1;
//     for (int i = 0; i < n; i++)
//     {
//         result[i] = prefix;
//         prefix *= nums[i];
//     }

//     // Compute suffix products and multiply with prefix
//     int suffix = 1;
//     for (int i = n - 1; i >= 0; i--)
//     {
//         result[i] *= suffix;
//         suffix *= nums[i];
//     }

//     return result;
// }

int main()
{
    vector<int> nums = {-1,-1,-1,-1,-1,-1,-1,-1,-1};
    vector<int> ans = productExceptSelf(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}