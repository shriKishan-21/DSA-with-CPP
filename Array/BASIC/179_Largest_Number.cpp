#include <bits/stdc++.h>
using namespace std;

static bool compare(int a, int b)
{
    string sa = to_string(a);
    string sb = to_string(b);
    return sa + sb > sb + sa;
}

string largestNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end(), compare);
    for(auto i : nums){
        cout << i << " "; 
    }   
    cout << endl;

    if (nums[0] == 0)
        return "0";

    string result;
    for (int num : nums)
    {
        result += to_string(num);
    }
    return result;
}

int main()
{
    vector<int> nums = {3, 30, 34, 5, 9};
    cout << largestNumber(nums);
}