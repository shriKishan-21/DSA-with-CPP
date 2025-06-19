#include<bits/stdc++.h>
using namespace std;


string removeDuplicates(string s) {
    int i =0;
    int j =1;
    while(j<s.length()){
        if(s[i]!=s[j]){
            i++;
            j++;
        }
        else{
            cout<<s<<endl;
            s.erase(i,j-i+1);
            cout<<s<<endl;
            i=0;
            j=1;
        }
    }
    return s;
}
int main(){
    string s = "abbaca";
    cout<<removeDuplicates(s);
}