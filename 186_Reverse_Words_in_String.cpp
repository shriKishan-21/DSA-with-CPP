#include <bits/stdc++.h>
using namespace std;

void REv(int i, int j, vector<char> &s)
{
    while (i < j)
    {
        swap(s[i++], s[j--]);
    }
}
void reverseWords(vector<char> &s)
{
    int i = 0;
    for (int j = 0; j < s.size(); j++)
    {
        if (s[j] == ' ')
        {
            REv(i, j - 1, s);
            i = j + 1;
        }
        if (j == s.size() - 1)
        {
            REv(i, j, s);
        }
    }
}

int main()
{
    vector<char> s = {'t', 'h', 'e', ' ', 's', 'k', 'y', ' ', 'i', 's', ' ', 'b', 'l', 'u', 'e'};
    reverseWords(s);
    REv(0, s.size() - 1, s); 
    for (auto i : s)
    {
        cout << i << " ";
    }
}