#include<bits/stdc++.h>
using namespace std;

void reverseString(vector<char>& s) {
    int b = 0;
    int e = s.size() - 1;
    while (b < e) {
        swap(s[b++], s[e--]);
    }
}

int main(){
    vector<char> s={'h','e','l','l','o'};
    reverseString(s);
    for(auto i:s){
        cout<<i<<" ";
    }
}