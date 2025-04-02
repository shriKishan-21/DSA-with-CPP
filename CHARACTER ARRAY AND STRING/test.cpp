#include<bits/stdc++.h>
using namespace std;


void Rev(int i, int j, string s) {
    while (i<=j) {
        swap(s[i++], s[j--]);
    }
}
string reverseString(string s) {
    int i = 0;
    for (int j = 0; j < s.length(); j++) {
        if (s[j] == ' ') {
            Rev(i, j - 1, s);
            i = j + 1;
        }
        if (j == s.length()) {
            Rev(i, j, s);
        }
    }
    return s;
}
int main()
{
    // vector<char> s = {'t', 'h', 'e', ' ', 's', 'k', 'y', ' ', 'i', 's', ' ', 'b', 'l', 'u', 'e'};
    string s = "the sky is blue";
    reverse(s.begin(), s.end());
    reverseString(s);
    for (auto i : s)
    {
        cout << i << " ";
    }
}