// TO CHECK FOR LOWERCASE AND IF ITS LOWERCASE THEN CONVERT IT TO UPPERCASE 
#include<bits/stdc++.h>
using namespace std;

char toLowerCase(char ch){
    if(ch>='a' && ch<='z'){
        return ch;
    }
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

char toUppercase(char ch){
    if(ch>='A' && ch<='Z'){
        return ch;
    }
    else{
        char temp = ch - 'a' + 'A';
        return temp;
    }
}

int main(){
    char a = 'h';
    char b = 'H';
    cout<<"Character in lowercase:"<<endl;
    cout<<toLowerCase(a)<<endl;
    cout<<toLowerCase(b)<<endl;

    cout<<"Character in uppercase:"<<endl;
    cout<<toUppercase(a)<<endl;
    cout<<toUppercase(b)<<endl;

}