#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s,int element){

    // base case
    if(s.empty()){
        s.push(element);
        return ;
    }

    int value = s.top();
    s.pop();

    insertAtBottom(s,element);

    s.push(value);

}
int main()
{
    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    int element = 1;

    insertAtBottom(s,element);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}