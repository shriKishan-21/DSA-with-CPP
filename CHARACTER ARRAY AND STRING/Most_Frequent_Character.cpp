#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "testsample";
    char ch[26]={0};
    int number=0;
    for(int i =0;i<s.length();i++){
        if(s[i]>='a' && s[i]<='z'){
            number = s[i] - 'a';
            cout<<number<<endl;
            ch[number]++;
        }
        
    }

    for(int i =0;i<26;i++){
            cout<<i<<" "<<ch[i]<<endl;
        }
}