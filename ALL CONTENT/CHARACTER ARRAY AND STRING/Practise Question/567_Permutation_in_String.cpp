#include<bits/stdc++.h>
using namespace std;

bool checkEqual(int count1[26],int count2[26]){
    for(int i=0;i<26;i++){
        if(count1[i]!=count2[i]){
            return false;
        }
    }
    return true;
}
int main()
{
    string s1 = "ab";
    string s2 = "eidbaooo";


    bool ans = false;
    // count & store s1 character
    int count1[26] = {0};
    for(int i=0;i<s1.length();i++){
        count1[s1[i]-'a']++;
    }

    // create and check window size
    int windowSize = s1.length();

    // count & store s2 character
    int count2[26] = {0};

    // running for first window
    int i = 0;
    while(i<windowSize && i<s2.length()){
        count2[s2[i]-'a']++;
        i++;
    }

    // if count1 & count2 are equal then return true
    if(checkEqual(count1,count2)){
        ans = true;
    }
    // proceed window further

    while(i<s2.length()){
        // here well remove first element and add next element
        int newChar = s2[i];
        count2[newChar-'a']++;

        int oldChar = s2[i-windowSize];
        count2[oldChar-'a']--;

        i++;

        if(checkEqual(count1,count2)){
            ans = true;
            break;
        }
    }

    cout<<ans<<endl;
}