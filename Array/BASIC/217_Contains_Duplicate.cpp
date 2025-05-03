#include <bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int> &nums)
{
    unordered_map<int, int> freq;
    for (int i : nums)
    {
        freq[i]++;
    }
    for (const auto &pair : freq)
    {
        if (pair.second > 1)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    vector<int> nums = {1, 2, 3, 1};
    cout << containsDuplicate(nums);
}