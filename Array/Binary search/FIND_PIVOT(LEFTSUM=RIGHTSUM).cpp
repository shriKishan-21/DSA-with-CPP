// FIND PIVOT INDEX

#include <bits/stdc++.h>
using namespace std;
int pivotIndex(vector<int> nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }                                                                                                             
    int leftsum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (leftsum == sum - nums[i] - leftsum)
        {
            return i;
        }
        leftsum += nums[i];
    }
    return -1;
}
int main()
{
    vector<int> nums = {1, 2, 3};
    cout << pivotIndex(nums);
}
