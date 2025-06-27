#include <bits/stdc++.h>
using namespace std;

void solve(string digits, string output, int index, vector<string> &ans, string mapping[])
{
    // base case
    if (index >= digits.length())
    {
        ans.push_back(output);
        return;
    }

    // find no and it mapping value
    int number = digits[index] - '0';
    string value = mapping[number];

    // recursive call
    for (int i = 0; i < value.length(); i++)
    {
        output.push_back(value[i]);
        solve(digits, output, index + 1, ans, mapping);
        // to remove the single character while backtracking
        output.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> ans;
    string output;
    int index = 0;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    // one condition where digits is empty
    if (digits.length() == 0)
    {
        return ans;
    }

    solve(digits, output, index, ans, mapping);

    return ans;
}
int main()
{
    string digits = "23";
    vector<string> ans = letterCombinations(digits);
    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}