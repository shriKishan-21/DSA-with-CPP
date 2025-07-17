#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

string reorganizeString(string s)
{
    
    string ans = "";

    map<char,int> mp;

    for(int i=0;i<s.length();i++){
        mp[s[i]]++;
    }

    priority_queue<pair<int,char>> pq;

    for(auto i:mp){
        pq.push({i.second,i.first});
    }

    while(pq.size()>1){
        pair<int,char> p1 = pq.top();
        pq.pop();

        pair<int,char> p2 = pq.top();
        pq.pop();

        ans += p1.second;
        ans += p2.second;

        if(p1.first>1){
            pq.push({p1.first-1,p1.second});
        }
        if(p2.first>1){
            pq.push({p2.first-1,p2.second});
        }
    }

    if(!pq.empty()){
        pair<int,char> p1 = pq.top();
        pq.pop();
        ans += p1.second;
        if(p1.first>1){
            pq.push({p1.first-1,p1.second});
        }

    }

    if(ans.length()!=s.length()){
        return ans;
    }
    else{
        return "";
    }

}
int main(){
    string s = "aabbcc";

    cout<<reorganizeString(s);
}