#include<iostream>
#include<stack>
using namespace std;


string reverseString(string str){
    // create stack
    stack<char> s;

    // push elements in the stack
    for(int i=0;i<str.length();i++)
    {
        s.push(str[i]);
    }

    string ans = "";
    // popping elements from the stack ans storing in stack
    while(!s.empty()){
        char ch = s.top();
        ans.push_back(ch);
        s.pop();
    }

    return ans;

}

int main()
{
    string str = "ashu";
    string ans = reverseString(str);

    cout<<ans<<endl;

    return 0;
}
