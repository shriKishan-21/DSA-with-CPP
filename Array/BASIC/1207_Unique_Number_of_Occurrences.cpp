#include <bits/stdc++.h>
using namespace std;

bool uniqueOccurrences(vector<int> &arr)
{
    unordered_map<int, int> freq;
    for (int i : arr)
    {
        freq[i]++;
    }

    unordered_set<int> dup;

    for (const auto &pair : freq)
    {
        if (dup.count(pair.second))
        {
            return false;
        }
        dup.insert(pair.second);
    }

    return true;
}
int main()
{
    vector<int> arr = {-12, 2, 21, -11, 8, -14, 16, -12, 4, 19, 17, -17, -14, -9, 20, 21, 12, -12, 15, -14, 11, 18};
    cout << uniqueOccurrences(arr);
}