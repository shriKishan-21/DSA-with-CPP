#include <iostream>
#include <vector>
#include <algorithm> 

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
        return result > 0 ? result : 0;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                long long triplet = (long long)(nums[i] - nums[j]) * nums[k];
                ans.push_back(triplet > 0 ? triplet : 0);
            }
        }
    }
    return *max_element(ans.begin(), ans.end());
}

int main()
{
    vector<int> nums = {1000000, 1, 1000000};
    cout << maximumTripletValue(nums);
}
