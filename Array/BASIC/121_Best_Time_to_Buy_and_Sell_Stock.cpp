#include <bits/stdc++.h>
using namespace std;

int min(vector<int> &prices)
{
    int mini = prices[0];
    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] < mini)
        {
            mini = prices[i];
        }
    }
    return mini;
}
int max(vector<int> &prices, int index)
{
    int maxi = prices[index];
    for (int i = index; i < prices.size(); i++)
    {
        if (prices[i] > maxi)
        {
            maxi = prices[i];
        }
    }
    return maxi;
}
int maxProfit(vector<int> &prices)
{
    int buy = min(prices), sell = 0;
    cout<<"buy: "<<buy<<endl;
    int index = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] == buy)
        {
            index = i;
            break;
        }
    }
    cout<<"index: "<<index<<endl;
    if (index == prices.size() - 1)
    {
        return 0;
    }
    else
    {
        sell = max(prices, index);
    }
    cout<<"sell: "<<sell<<endl;
    if (sell - buy <= 0)
    {
        return 0;
    }
    return sell - buy;
}

int main(){
    vector<int> arr={7,1,5,3,6,4};
    cout<<maxProfit(arr);
    cout<<endl;
    cout<<max(arr,1);
}