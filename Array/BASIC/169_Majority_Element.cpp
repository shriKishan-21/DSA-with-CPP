#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums)
{
    unordered_map<int, int> freq;
    for (int i : nums)
    {
        freq[i]++;
    }
    int majo = nums.size() / 2;

    for (const auto &pair : freq)
    {
        if (pair.second > majo)
        {
            return pair.first;
        }
    }
    return 0;
}
int main()
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << majorityElement(nums);
}