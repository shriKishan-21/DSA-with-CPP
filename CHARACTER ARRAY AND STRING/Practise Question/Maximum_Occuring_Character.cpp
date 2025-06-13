#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "testsample";

    int arr[26]={0};
    for(int i=0;i<s.length();i++){
        arr[s[i]-'a']++;
    }

    int maxi=-1,ans=0;
    for(int i=0;i<26;i++){
        if(maxi<arr[i]){
            ans=i;
            maxi=arr[i];
        }
    }
    
    cout<<char(ans+'a');
}