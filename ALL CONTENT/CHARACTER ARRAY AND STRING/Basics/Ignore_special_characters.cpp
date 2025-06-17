#include <bits/stdc++.h>
using namespace std;

bool ignoreSpecialCharacters(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
    {
        return true;
    }
    return false;
}
int main()
{
    string s = "ABCDefgh1234!@#";
    for (int i = 0; i < s.length(); i++)
    {
        if(ignoreSpecialCharacters(s[i])){
            cout<<s[i];
        }
    }
}