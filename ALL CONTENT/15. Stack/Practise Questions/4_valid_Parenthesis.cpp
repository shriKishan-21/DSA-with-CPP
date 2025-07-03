#include<iostream>
#include<stack>
using namespace std;


bool isValidParenthesis(string str){

    // create stack to store opening bracke
    stack<char> s;
    // insert opening char
    for(int i=0;i<str.length();i++){
        char ch = str[i];

        // if opening bracket -- push into stack
        if(ch=='(' || ch=='{' || ch=='['){
            s.push(ch);
        }
        // else closing bracket -- match wih opening bracket 
        // if matches pop opening bracket else return false
        else{
            // first for once check if stack is empty -- if not proceed else return false(because that means either closing bracket appear first or there is no opening bracket remaining)
            if(!s.empty()){
                char top = s.top();
                // check if ch and top element matches
                if((ch==')' && top=='(') || (ch=='}' && top=='{') || (ch==']' && top=='[')){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            } 
        }
    }

    // check if your stack become empty -- every opening bracket has closing bracket -- valid parenthesis
    if(s.empty()){
        return true;
    }
    else{
        return false;
    }
}
int main()
{
    string str = "({[]})";
    cout<<isValidParenthesis(str)<<endl;

}