#include<iostream>
#include<stack>
using namespace std;

bool findRedundantBracket(string &s){
    // create a stack
    stack<char> str;

    for(int i=0;i<s.length();i++){
        char ch = s[i];

        // store only opening bracket and operaters in stack
        if(ch=='(' || ch=='+' || ch=='-' || ch=='*'|| ch=='/'){
            str.push(ch);
        } 
        else{
            // if closing bracket are present
            if(ch==')'){
                // we check it top is an operator the it is not a redundant bracket
                bool isRedundant = true;

                while(str.top() != '('){
                    char top = str.top();
                    if(top=='+' || top=='-' || top=='*'|| top=='/'){
                        isRedundant = false;
                    }
                    str.pop();
                }
                if(isRedundant==true)
                    return true;
                str.pop();
            }
        }
    }
    return false;
}
int main()
{

    string s = "(a*b+(c/d))";

    cout<< findRedundantBracket(s);   

    return 0;
}