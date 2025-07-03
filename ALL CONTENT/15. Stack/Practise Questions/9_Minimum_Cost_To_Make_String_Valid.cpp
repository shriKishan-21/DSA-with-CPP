#include<iostream>
#include<stack>
using namespace std;

int findMinimumCost(string &s){

    // check for odd condition
    if(s.length()%2 == 1){
        return -1;
    }
    // create a stack
    stack<char> str;

    for(int i=0;i<s.length();i++){
        char ch = s[i];

        // store only opening braces
        if(ch=='{'){
            str.push(ch);
        } 
        else{
            // if top is an opening braces and stack is not empty
            if(!str.empty() && str.top()=='{'){
                str.pop();
            }
            else{
                str.push(ch);
            }
        }
    }


    // count open and close braces
    int a = 0; // close braces
    int b = 0; // open braces
    
    while(!str.empty()){
        if(str.top()=='{'){
            b++;
        }
        else{
            a++;
        }
        str.pop();
    }

    int ans = (a+1)/2 + (b+1)/2;

    return ans;
}
int main()
{

    string s = "}}}{{{";

    cout<< findMinimumCost(s);   

    return 0;
}