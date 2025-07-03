#include<iostream>
#include<stack>
using namespace std;



void sortedInsert(stack<int> &s , int element){
    // base case
    if(s.empty() || (!s.empty() && s.top()<element)){
        s.push(element);
        return;
    }

    int value = s.top();
    s.pop();


    sortedInsert(s,element);

    s.push(value);

}
void sortStack(stack<int> &s){
    // base case
    if(s.empty()){
        return;
    }

    int topElement = s.top();
    s.pop();

    // recursion
    sortStack(s);

    sortedInsert(s,topElement);
}
int main()
{
    stack<int> s;
    s.push(5);
    s.push(3);
    s.push(0);
    s.push(9);

    
    sortStack(s);
    
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}