#include<iostream>
#include<stack>
using namespace std;



void insertAtBottom(stack<int> &s , int element){
    // base case
    if(s.empty()){
        s.push(element);
        return;
    }

    int value = s.top();
    s.pop();


    insertAtBottom(s,element);

    s.push(value);

}
void reverse(stack<int> &s){
    // base case
    if(s.empty()){
        return;
    }

    int topElement = s.top();
    s.pop();

    // recursion
    reverse(s);

    insertAtBottom(s,topElement);
}
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    
    reverse(s);
    
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}