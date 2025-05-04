#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int mini = prices[0], res = 0;
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, prices[i]);

        res = max(res, prices[i] - mini);
    }
    return res;
}

int main()
{
    vector<int> arr = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(arr);
}