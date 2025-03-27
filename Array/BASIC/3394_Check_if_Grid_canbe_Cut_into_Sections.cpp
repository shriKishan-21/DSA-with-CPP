#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> verticalCut(int n, vector<vector<int>> &rectangles)
{
    vector<vector<int>> ysample;
    for (auto i : rectangles)
    {
        ysample.push_back({i[1], i[3]});
    }
    return ysample;
}

vector<vector<int>> horizontalcut(int n, vector<vector<int>> &rectangles)
{
    vector<vector<int>> xsample;
    for (auto i : rectangles)
    {
        xsample.push_back({i[0], i[2]});
    }
    return xsample;
}
bool checkValidCuts(int n, vector<vector<int>> &rectangles)
{
    vector<vector<int>> ysample = verticalCut(5, rectangles);
    vector<vector<int>> xsample = horizontalcut(5, rectangles);

    sort(ysample.begin(), ysample.end());
    sort(xsample.begin(), xsample.end());

    for (int i = 0; i < n - 1; i++)
    {
        if (ysample[i][1] > xsample[i][1])
        {
            return false;
        }
    }

    return true;
}
int main()
{
    vector<vector<int>> rectangles = {{1, 1, 3, 3}, {3, 1, 4, 2}, {3, 2, 4, 4}, {1, 3, 2, 4}, {2, 3, 3, 4}};

    vector<vector<int>> ysample = verticalCut(5, rectangles);
    // vector<vector<int>> ysample;
    // ysample.push_back({1, 3});
    // ysample.push_back({1, 2});
    // ysample.push_back({2, 1});
    // ysample.push_back({3, 1});
    // ysample.push_back({0, 0});
    // sort(ysample.begin(), ysample.end());
    cout << "ySample" << endl;

    for (auto i : ysample)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    // cout<<"xSamples"<<endl;

    // vector<vector<int>> xsample = horizontalcut(5, rectangles);
    // for (auto i : xsample)
    // {
    //     for (auto j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}