#include<bits/stdc++.h>
using namespace std;

string removeOccurrences(string s, string part) {
    // check while the length of string is not 0 and the part find is not out of string length
    while(s.length()!=0 && s.find(part)<s.length()){
        // erase all the part from staring of part to end of part
        s.erase(s.find(part),part.length());
        // s.erase(start,end);
    }
    return s;
}
int main()
{
    string s = "daabcbaabcbc";
    string part = "abc";
    cout<<removeOccurrences(s,part);
}