#include<iostream>
#include<stack>
using namespace std;


void solve(stack<int> &s,int count,int size){

    // base case
    if(count==size/2){
        // remove middle element
        s.pop();
        return ;
    }

    // store the element at the top of the stack - until we reach the middle element
    int num = s.top();
    s.pop();

    // recursive call
    solve(s,count+1,size);

    // push the stored element back to the stack -- because we need to restore the stack
    s.push(num);

}

void deleteMiddle(stack<int> &s, int N)
{
    int count = 0;
    solve(s,count,N);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    deleteMiddle(s,5);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}