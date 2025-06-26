#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(string& str , int i , int j){
    // base case
    if(i>j){
        return true;
    }

    if(str[i]!=str[j]){
        return false;
    }
    else{
        checkPalindrome(str,i+1,j-1);
    }
}
int main()
{
    string str = "adcba";
    cout<<checkPalindrome(str,0,str.length()-1);
}