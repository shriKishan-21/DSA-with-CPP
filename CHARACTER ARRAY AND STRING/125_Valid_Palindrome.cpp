#include<bits/stdc++.h>
using namespace std;


char toLower(char ch){
    if((ch>='a' && ch<='z') || (ch>='0' && ch<='9')){
        return ch;
    }
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}
bool isValidChar(char ch){
    if((ch>='a' && ch<='z') || (ch>='A' && ch<='z') || (ch>='0' && ch<='9')){
        return true;
    }
    return false;
}
bool checkPalindrome(string s){
    int i =0;
    int j = s.length()-1;
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

bool isPalindrome(string s){
    // removing unwanted characters
    string temp = "";
    for(int i =0;i<s.length();i++){
        if(isValidChar(s[i])){
            temp.push_back(s[i]);
        }
    }

    for(int i =0;i<temp.length();i++){
        temp[i] = toLower(temp[i]);
    }

    return checkPalindrome(temp);
}
int main()
{
    string s = "A man, a plan, a canal: Panama";  
    cout<<isPalindrome(s);  

}