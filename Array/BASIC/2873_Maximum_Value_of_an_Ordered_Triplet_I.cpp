#include <bits/stdc++.h>
using namespace std;

long long maximumTripletValue(vector<int> &nums)
{
    vector<long long> ans;
    if (nums.size() < 3)
    {
        return 0;
    }
    else if (nums.size() == 3)
    {
        long long result = (long long)(nums[0] - nums[1]) * nums[2];
        if (result > 0)
        {
            return result;
        }
        else
        {
            return 0;
        }
    }
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                long long triplet =
                    (long long)(nums[i] - nums[j]) * nums[k];
                if (triplet > 0)
                {
                    ans.push_back(triplet);
                }
                else
                {
                    ans.push_back(0);
                }
            }
        }
    }
    long long sol = *max_element(ans.begin(), ans.end());
    return sol;
}
int main()
{
    vector<int> nums = {1000000, 1, 1000000};
    cout << maximumTripletValue(nums);
}